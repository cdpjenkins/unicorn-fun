#include <iostream>
using namespace std;

#include "pico/cyw43_arch.h"
#include "lwip/tcp.h"
#include "wifi_settings.h"

#include "Agent.hpp"
#include "MQTTAgent.hpp"

MQTTAgent::MQTTAgent() :
        Agent("mqtt_agent",
              configMINIMAL_STACK_SIZE * 4,
              tskIDLE_PRIORITY + 1)
{

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

    while (true) {
        cout << "Meh" << endl;
        vTaskDelay(10000);
    }
}
