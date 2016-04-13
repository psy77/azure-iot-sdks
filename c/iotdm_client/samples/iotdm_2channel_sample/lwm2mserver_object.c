

// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

//
// Simple implementation of IoTHub LWM2M LWM2M Server object
//

//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if defined(WIN32)
#include <windows.h>
#include <tchar.h>
#endif

#include "iothub_lwm2m.h"
#include "iotdm_lwm2m_client_apis.h"
#include "liblwm2m.h"


/**********************************************************************************
 * Callback prototypes
 *
 **********************************************************************************/

IOTHUB_CLIENT_RESULT on_read_lwm2mserver_lifetime(int *value);
IOTHUB_CLIENT_RESULT on_write_lwm2mserver_lifetime(int value);
IOTHUB_CLIENT_RESULT on_read_lwm2mserver_defaultminimumperiod(int *value);
IOTHUB_CLIENT_RESULT on_write_lwm2mserver_defaultminimumperiod(int value);
IOTHUB_CLIENT_RESULT on_read_lwm2mserver_defaultmaximumperiod(int *value);
IOTHUB_CLIENT_RESULT on_write_lwm2mserver_defaultmaximumperiod(int value);

/**********************************************************************************
 * Default property implmentations
 *
 **********************************************************************************/
int propval_lwm2mserver_lifetime = 0;
int propval_lwm2mserver_defaultminimumperiod = 0;
int propval_lwm2mserver_defaultmaximumperiod = 0;

void set_default_lwm2mserver_values()
{
    propval_lwm2mserver_lifetime = -1;
    propval_lwm2mserver_defaultminimumperiod = -1;
    propval_lwm2mserver_defaultmaximumperiod = -1;
}

/**********************************************************************************
 * CALLBACK REGISTRATION
 *
 **********************************************************************************/
IOTHUB_CLIENT_RESULT register_all_lwm2mserver_callbacks(IOTHUB_CHANNEL_HANDLE h)
{
    if (
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_Lifetime_SetReadCallback(h, on_read_lwm2mserver_lifetime)) ||
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_Lifetime_SetWriteCallback(h, on_write_lwm2mserver_lifetime)) ||
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_DefaultMinimumPeriod_SetReadCallback(h, on_read_lwm2mserver_defaultminimumperiod)) ||
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_DefaultMinimumPeriod_SetWriteCallback(h, on_write_lwm2mserver_defaultminimumperiod)) ||
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_DefaultMaximumPeriod_SetReadCallback(h, on_read_lwm2mserver_defaultmaximumperiod)) ||
        (IOTHUB_CLIENT_OK != IotHubClient_LWM2MServer_DefaultMaximumPeriod_SetWriteCallback(h, on_write_lwm2mserver_defaultmaximumperiod)) ||
        false
        )
    {
        LogError("Failure setting callback in LWM2M Server object\r\n");

        return IOTHUB_CLIENT_ERROR;
    }

    return IOTHUB_CLIENT_OK;
}

/**********************************************************************************
 * OBJECT REGISTRATION
 *
 **********************************************************************************/
IOTHUB_CLIENT_RESULT register_lwm2mserver_object(IOTHUB_CLIENT_HANDLE h)
{
    set_default_lwm2mserver_values();
    if (IOTHUB_CLIENT_OK != register_all_lwm2mserver_callbacks(h))
    {
        LogError("setting default values for LWM2M Server object\r\n");

        return IOTHUB_CLIENT_ERROR;
    }

    if (IOTHUB_CLIENT_OK != IoTHubClient_DM_AddNewObject(h, 1))
    {
        LogError("Failure to add the LWM2M Server object for client: %p\r\n", h);

        return IOTHUB_CLIENT_ERROR;
    }

    return IOTHUB_CLIENT_OK;
}

/**********************************************************************************
 * CALLBACK HANDLERS
 *
 **********************************************************************************/
IOTHUB_CLIENT_RESULT on_read_lwm2mserver_lifetime(int *value)
{
    LogInfo("inside reader for LWM2MServer_Lifetime\r\n");

    LogInfo("returning %d\r\n", propval_lwm2mserver_lifetime);
    *value = propval_lwm2mserver_lifetime;

    return IOTHUB_CLIENT_OK;
}

IOTHUB_CLIENT_RESULT on_write_lwm2mserver_lifetime(int value)
{
    LogInfo("inside writer for LWM2MServer_Lifetime\r\n");

    LogInfo("setting to %d\r\n", value);
    propval_lwm2mserver_lifetime = value;

    return IOTHUB_CLIENT_OK;
}

IOTHUB_CLIENT_RESULT on_read_lwm2mserver_defaultminimumperiod(int *value)
{
    LogInfo("inside reader for LWM2MServer_DefaultMinimumPeriod\r\n");

    LogInfo("returning %d\r\n", propval_lwm2mserver_defaultminimumperiod);
    *value = propval_lwm2mserver_defaultminimumperiod;

    return IOTHUB_CLIENT_OK;
}

IOTHUB_CLIENT_RESULT on_write_lwm2mserver_defaultminimumperiod(int value)
{
    LogInfo("inside writer for LWM2MServer_DefaultMinimumPeriod\r\n");

    LogInfo("setting to %d\r\n", value);
    propval_lwm2mserver_defaultminimumperiod = value;

    return IOTHUB_CLIENT_OK;
}

IOTHUB_CLIENT_RESULT on_read_lwm2mserver_defaultmaximumperiod(int *value)
{
    LogInfo("inside reader for LWM2MServer_DefaultMaximumPeriod\r\n");

    LogInfo("returning %d\r\n", propval_lwm2mserver_defaultmaximumperiod);
    *value = propval_lwm2mserver_defaultmaximumperiod;

    return IOTHUB_CLIENT_OK;
}

IOTHUB_CLIENT_RESULT on_write_lwm2mserver_defaultmaximumperiod(int value)
{
    LogInfo("inside writer for LWM2MServer_DefaultMaximumPeriod\r\n");

    LogInfo("setting to %d\r\n", value);
    propval_lwm2mserver_defaultmaximumperiod = value;

    return IOTHUB_CLIENT_OK;
}

