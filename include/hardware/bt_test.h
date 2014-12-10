/*
 * Copyright (C) 2012-2013 Intel Mobile Communications GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_INCLUDE_BT_TEST_H
#define ANDROID_INCLUDE_BT_TEST_H

__BEGIN_DECLS

#define L2CAP_PARAMETER_CLEAR           0
#define L2CAP_PARAMETER_MODE            1
#define L2CAP_PARAMETER_SEND_CONFIG     2
#define L2CAP_PARAMETER_SET_ERTM        3
#define L2CAP_PARAMETER_SET_MTU         4
#define L2CAP_PARAMETER_SET_FLUSH_TO    5
#define L2CAP_PARAMETER_SET_FCS         6
#define L2CAP_PARAMETER_SET_FCR         7

#define TC_SUCCESS                      0
#define TC_FAILURE                      1
#define TC_WAIT_TIME                    30

#define TC_CMD_EXEC_WAIT                0xFF

#define TC_EVENT_EXEC_WAIT              0
#define TC_EVENT_EXEC_CONT              1
#define TC_EVENT_EXEC_EXIT              2
#define TC_EVENT_EXEC_TOUT              3
#define TC_EVENT_CONN_CFM               4
#define TC_EVENT_CONN_FAILED            5
#define TC_EVENT_VER_PASS               6
#define TC_EVENT_VER_FAIL               7
#define TC_EVENT_VER_INCONC             8

#define TC_VERDICT_PASS                 0xFE
#define TC_VERDICT_FAIL                 0xFD
#define TC_VERDICT_INCONC               0xFC

#ifdef VERIFIER
#ifdef BNEP_VERIFIER
typedef struct {
    size_t size;
    void (*fnBNEPV_init) ( void * );
    void (*fnBNEPV_set_remote_bd_addr) ( bt_bdaddr_t * );
    void (*fnBNEPV_select_test_case) ( uint8_t, uint8_t * );
    uint8_t (*fnBNEPV_get_cmd) ( void );
    void (*fnBNEPV_connect) ( void );
    void (*fnBNEPV_send_control_msg) ( uint8_t );
    void (*fnBNEPV_disconnect) ( void );
} bnep_verifier_interface_t;
#endif

#ifdef AVDTP_VERIFIER
typedef struct {
    size_t size;
    void (*fnAVDTPV_init) ( void * );
    void (*fnAVDTPV_set_remote_bd_addr) ( bt_bdaddr_t * );
    void (*fnAVDTPV_set_invalid_mode) ( int );
    void (*fnAVDTPV_select_test_case) ( uint8_t, uint8_t * );
    uint8_t (*fnAVDTPV_get_cmd) ( void );
    void (*fnAVDTPV_connect) ( void );
    void (*fnAVDTPV_send_control_msg) ( uint8_t );
    void (*fnAVDTPV_disconnect) ( void );
} avdtp_verifier_interface_t;
#endif

#endif // VERIFIER

#ifdef TESTER
#ifdef L2CAP_TESTER
typedef struct {
    size_t size;
    uint16_t (*L2CAPTest_init)(void);
    void (*L2CAPTest_set_default_parameters)(void);
    void (*L2CAPTest_set_parameters)(uint8_t, void *);
    void (*L2CAPTest_set_remote_bd_addr)(bt_bdaddr_t *);
    void (*L2CAPTest_connect)(void);
    void (*L2CAPTest_disconnect)(void);
    void (*L2CAPTest_senddata)(uint16_t);
    void (*L2CAPTest_ping)(uint8_t);
    void (*L2CAPTest_cleanup)(void);
} l2cap_test_interface_t;
#endif

#ifdef BNEP_TESTER
typedef struct {
    size_t size;
    void (*BNEPTest_init)(void);
    void (*BNEPTest_send_control_msg)(uint8_t);
} bnep_test_interface_t;
#endif

#ifdef AVDTP_TESTER
typedef struct {
    size_t size;
    void (*AVDTPTest_init)(void);
    void (*AVDTPTest_send_control_msg)(uint8_t);
    void (*AVDTPTest_set_remote_bd_addr) ( bt_bdaddr_t * );
} avdtp_test_interface_t;
#endif

#endif  // TESTER

__END_DECLS

#endif /* ANDROID_INCLUDE_BT_TEST_H */
