#include "api-keys.h"
#include <stdio.h>

#include <olp/core/client/OlpClient.h>
#include <olp/core/client/OlpClientFactory.h>
#include <olp/core/client/OlpClientSettingsFactory.h>
#include <olp/core/CoreApi.h>
#include <olp/core/platform/Context.h>
#include <olp/core/model/Api.h>

int main(int argc, char const *argv[])
{
    // Initialize OLP SDK
    olp::client::OlpClientSettings settings;
    olp::client::AuthenticationSettings auth_settings;
	auth_settings.api_key_provider = []() {
		return HERE_MAPS_API_KEY;
	};

    settings.authentication_settings = auth_settings;
	settings.network_request_handler = olp::client::OlpClientSettingsFactory::CreateDefaultNetworkRequestHandler();
    olp::client::OlpClient client(settings, "https://router.hereapi.com/v8/");

	olp::client::OlpClient::ParametersType query_params;
	query_params.insert(std::make_pair(std::string("transportMode"), std::string("car")));
	query_params.insert(std::make_pair(std::string("origin"), std::string("60.16396503389212,24.933858781345762")));
	query_params.insert(std::make_pair(std::string("destination"), std::string("65.20026853635363,29.05781393954109")));
	query_params.insert(std::make_pair(std::string("routingMode"), std::string("fast")));
	query_params.insert(std::make_pair(std::string("return"), std::string("polyline,turnByTurnActions")));

	/*olp::client::NetworkAsyncCallback callback = std::function<void(olp::client::HttpResponse)>([](olp::client::HttpResponse response)->void {
		
	});*/

	olp::client::CancellationContext cc;
	olp::client::HttpResponse response = client.CallApi(std::string("routes"), std::string ("GET"), query_params, {}, {}, {}, "application/json", cc);

	std::string s;
	response.GetResponse(s);

	printf ("%s\n", s.c_str());
	return 0;
}
