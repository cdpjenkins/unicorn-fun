add_executable(${NAME}
        main.cpp
		Agent.cpp
		CLIAgent.cpp
		cosmic/CosmicUnicornDisplayAgent.cpp
		MQTTAgent.cpp
		WithMutexLock.cpp
		conway/ConwayGrid.cpp
        cosmic/ScrollTextApp.cpp
		cosmic/App.cpp)

include(libraries/pico_unicorn/pico_unicorn)

if (NOT wifi_settings.h)
	configure_file(../templates/wifi_settings_template.h wifi_settings.h COPYONLY)
endif()

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME}
		pico_stdlib
		FreeRTOS-Kernel-Heap4
		hardware_pio
		hardware_dma
		cosmic_unicorn

		cyw43_driver_picow
		pico_cyw43_arch_lwip_sys_freertos
		pico_lwip_mqtt
		)

target_include_directories(${NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
     )
     
target_compile_definitions(${NAME} PRIVATE
    configNUM_CORES=1
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)