/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file  event/pod.h
 * @brief pod definitions
 *
 * @addtogroup APACHE_MPM_EVENT
 * @{
 */

#include "apr.h"
#include "apr_strings.h"
#define APR_WANT_STRFUNC
#include "apr_want.h"

#include "httpd.h"
#include "http_config.h"
#include "http_log.h"
#include "http_main.h"
#include "mpm_common.h"
#include "ap_mpm.h"
#include "ap_listen.h"
#include "mpm_default.h"

#define RESTART_CHAR '$'
#define GRACEFUL_CHAR '!'
#define RECONFIGURE_CHAR '#' /*amiya 20140217*/

#define AP_RESTART  0
#define AP_GRACEFUL 1
#define AP_RECONFIGURE 2	/*amiya 20140217*/

typedef struct ap_event_pod_t ap_event_pod_t;

struct ap_event_pod_t
{
    apr_file_t *pod_in;
    apr_file_t *pod_out;
    apr_pool_t *p;
};

AP_DECLARE(apr_status_t) ap_event_pod_open(apr_pool_t * p, ap_event_pod_t ** pod);
AP_DECLARE(int) ap_event_pod_check(ap_event_pod_t * pod);
AP_DECLARE(apr_status_t) ap_event_pod_close(ap_event_pod_t * pod);
AP_DECLARE(apr_status_t) ap_event_pod_signal(ap_event_pod_t * pod, int graceful);
AP_DECLARE(void) ap_event_pod_killpg(ap_event_pod_t * pod, int num, int graceful);
/** @} */
