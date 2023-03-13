#include <iostream>
using namespace std;

#include "pico/cyw43_arch.h"
#include "lwip/tcp.h"
#include "wifi_settings.h"

#include "Agent.hpp"
#include "MQTTAgent.hpp"

static const struct mqtt_connect_client_info_t mqtt_client_info =
        {
                "test",
                MQTT_USERNAME,
                MQTT_PASSWORD,
                100,
                NULL,
                NULL,
                0,
                0
        };

MQTTAgent::MQTTAgent() :
        Agent("mqtt_agent",
              configMINIMAL_STACK_SIZE * 4,
              tskIDLE_PRIORITY + 1)
{

}

static void
mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len) {
    static_cast<MQTTAgent *>(arg)->incoming_publish_cb(topic, tot_len);
}

static void
mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags) {
    static_cast<MQTTAgent *>(arg)->incoming_data_cb(data, len, flags);
}

static void
mqtt_request_cb(void *arg, err_t err)
{
    const struct MQTTAgent* agent = (MQTTAgent *)arg;

    printf("MQTT client \"%s\" request cb: err %d\n",
           agent->get_name(),
           (int)err);
}

static void
mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status)
{
    const struct MQTTAgent* agent = (MQTTAgent *)arg;

    printf("MQTT client \"%s\" connection cb: status %d\n",
           agent->get_name(),
           (int)status);

    if (status == MQTT_CONNECT_ACCEPTED) {
        mqtt_sub_unsub(client,
                       MQTT_QUEUE,
                       1,
                       mqtt_request_cb,
                       LWIP_CONST_CAST(void*, agent),
                       1);
    }
}

void MQTTAgent::task_main() {
    int rc;

    cout << "Setting up WiFI" << endl;
    cout << "Initialising CYW43... " << endl;
    rc = cyw43_arch_init_with_country(CYW43_COUNTRY_UK);
    if (rc) {
        cout << "Return code: " << rc;
        throw runtime_error("Failed to init CYW43");
    }
    cout << "Initialising CYW34 done." << endl;

    cyw43_arch_enable_sta_mode();

    cout << "Connecting to WiFi... ";
    rc = cyw43_arch_wifi_connect_blocking(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_MIXED_PSK);
    if (rc) {
        cout << "Return code: " << rc;
        throw runtime_error("Failed to connect to WiFi");
    }
    cout << "Connected!" << endl;

    cout << "IP address: " << ip4addr_ntoa(netif_ip_addr4(netif_default)) << endl;
    cout << "Netmask:    " << ip4addr_ntoa(netif_ip_netmask4(netif_default)) << endl;
    cout << "Gateway:    " << ip4addr_ntoa(netif_ip_gw4(netif_default)) << endl;
    cout << "Hostname:   " << netif_get_hostname(netif_default) << endl;

    mqtt_client_t *mqtt_client;

    mqtt_client = mqtt_client_new();

    mqtt_set_inpub_callback(mqtt_client,
                            mqtt_incoming_publish_cb,
                            mqtt_incoming_data_cb,
                            this);

    ip_addr_t mqtt_ip;
    ip4_addr_set_u32(&mqtt_ip, ipaddr_addr("192.168.1.51"));

    mqtt_client_connect(mqtt_client,
                        &mqtt_ip,
                        MQTT_PORT,
                        mqtt_connection_cb,
                        this,
                        &mqtt_client_info);

    while (true) {
        vTaskDelay(1000);
    }
}

void MQTTAgent::incoming_publish_cb(const char *topic, u32_t tot_len) {
    printf("MEMBER: MQTT client \"%s\" publish cb: topic %s, len %d\n",
           get_name(),
           topic,
           (int)tot_len);
}

void MQTTAgent::incoming_data_cb(const u8_t *data, u16_t len, u8_t flags) {
    printf("MEMBER: MQTT client \"%s\" data cb: len %d, flags %d\n",
           get_name(),
           (int)len,
           (int)flags);

    int length = len;
    if (length > 64-1) {
        length = 64-1;
    }

    if (flags & MQTT_DATA_FLAG_LAST) {
        char message[64];

        memcpy(message, data, length);
        message[length] = '\0';

        printf("message: %s\n", message);
    } else {
        printf("More than one packet, which we can't currently handle\n");
    }
}
