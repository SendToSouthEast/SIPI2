# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS "main.c"
         "init.c"
        
         "fonts_imgs/simhei.c"
         "fonts_imgs/arial.c"
         "fonts_imgs/but_but2.c"

         "scenes/dictScene.c"
         "scenes/wordScene.c"
         "scenes/HIDScene.c"
         "scenes/mainScene.c"
         "scenes/calcScene.c"

         "srcs/blueHID/ble_hidd.c"
         "srcs/blueHID/esp_hidd_prf_api.c"
         "srcs/blueHID/hid_dev.c"
         "srcs/blueHID/hid_device_le_prf.c"

         "srcs/englishDict/englishDict.c"

         "srcs/calculate/calculate.c"

    INCLUDE_DIRS        # optional, add here public include directories
    PRIV_INCLUDE_DIRS
        "."
        "scenes"
        "fonts_imgs"
        "srcs"
        "srcs/blueHID"
        "srcs/englishDict"
        "srcs/calculate"
        
        
    REQUIRES
    PRIV_REQUIRES       # optional, list the private requirements
)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-const-variable)