/*-----------------------------------------*\
|  SteelSeriesOldApexController.h           |
|                                           |
|  Definitions and types for SteelSeries    |
|  older Apex KB lighting controller        |
|  (Apex, Apex Fnatic, Apex 350)            |
|                                           |
|  David Lee (RAMChYLD) 15/11/2020          |
|                                           |
|  Based on work for SteelSeries Rival by   |
|  B Horn    (bahorn)   13/5/2020           |
|                                           |
|  Based on findings in ApexCtl by          |
|  Audrius/tuxmark5, et. al                 |
|  https://github.com/tuxmark5/ApexCtl      |
\*-----------------------------------------*/

#include <string>
#include <hidapi/hidapi.h>

#include "color32.h"
#include "SteelSeriesGeneric.h"

#pragma once

/* Mode, we then use these to set actual effect based on speed. */
enum
{
    STEELSERIES_OLDAPEX_BRIGHTNESS_1 = 0x01,
    STEELSERIES_OLDAPEX_BRIGHTNESS_2 = 0x02,
    STEELSERIES_OLDAPEX_BRIGHTNESS_3 = 0x03,
    STEELSERIES_OLDAPEX_BRIGHTNESS_4 = 0x04,
    STEELSERIES_OLDAPEX_BRIGHTNESS_5 = 0x05,
    STEELSERIES_OLDAPEX_BRIGHTNESS_6 = 0x06,
    STEELSERIES_OLDAPEX_BRIGHTNESS_7 = 0x07,
    STEELSERIES_OLDAPEX_BRIGHTNESS_8 = 0x08,
};

/* Effects */
enum
{
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_1 = 0x01,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_2 = 0x02,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_3 = 0x03,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_4 = 0x04,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_5 = 0x05,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_6 = 0x06,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_7 = 0x07,
    STEELSERIES_OLDAPEX_EFFECT_BRIGHTNESS_8 = 0x08,
};

class SteelSeriesOldApexController
{
public:
    SteelSeriesOldApexController
        (
        hid_device*         dev_handle,
        steelseries_type    proto_type,
        const char*         path
        );

    ~SteelSeriesOldApexController();

    std::string GetDeviceLocation();
    char*       GetDeviceName();
    std::string GetSerialString();

    steelseries_type GetKeyboardType();

    void SetColorDetailed
        (
            color32 qwerty,
            color32 tenkey,
            color32 functionkey,
            color32 mxkey,
            color32 logo
        );

    void DoUpdateLEDs();

private:
    char                    device_name[32];
    hid_device*             dev;
    std::string             location;
    steelseries_type        proto;
};
