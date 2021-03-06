/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2019-2020 The Fluent Bit Authors
 *  Copyright (C) 2015-2018 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <fluent-bit/flb_info.h>
#include <mpack/mpack.h>

int flb_mp_count(const void *data, size_t bytes)
{
    int count = 0;
    mpack_reader_t reader;

    mpack_reader_init_data(&reader, (const char *) data, bytes);
    while (mpack_reader_remaining(&reader, NULL) > 0) {
        count++;
        mpack_discard(&reader);
    }

    mpack_reader_destroy(&reader);
    return count;
}
