/*
  Copyright (c) 2023 Sogou, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef __RPC_HTTP_SERVER_H__
#define __RPC_HTTP_SERVER_H__

#include "workflow/WFHttpServer.h"
#include "rpc_basic.h"
#include "rpc_filter.h"
#include "rpc_module.h"

namespace srpc
{

class HttpServer : public WFHttpServer
{
public:
	HttpServer(http_process_t proc) :
		WFHttpServer(std::move(proc)),
		listen_port(0)
	{
	}

	void add_filter(RPCFilter *filter);

protected:
	CommSession *new_session(long long seq, CommConnection *conn) override;

private:
	unsigned short get_listen_port();

private:
	std::mutex mutex;
	RPCModule *modules[SRPC_MODULE_MAX] = { NULL };
	unsigned short listen_port;
};

} // namespace srpc

#endif

