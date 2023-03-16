#!/bin/sh

#
# Publish a command to the cosmic_commands topic. Assumes that certain environment variables have been set up.
#

# Assumes you have the mosquitto client installed
#
# You'll probably want one of the following:
#
# brew install mosquitto
#
# sudo apt install mosquitto-clients

mosquitto_pub -h ${MQTT_HOST_IP_ADDR} -t "cosmic_commands" -u "${MQTT_USER}" -P "${MQTT_PASSWORD}"  -m "$1"
