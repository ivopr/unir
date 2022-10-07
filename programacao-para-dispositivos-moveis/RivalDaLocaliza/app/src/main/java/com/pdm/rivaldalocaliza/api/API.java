package com.pdm.rivaldalocaliza.api;

import com.pdm.rivaldalocaliza.api.services.AuthenticationService;
import com.pdm.rivaldalocaliza.api.services.RentService;

import lombok.Getter;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

@Getter
public class API {
	Retrofit api;
	RentService rentService;
	AuthenticationService authenticationService;

	public API() {
		api = new Retrofit.Builder()
			.baseUrl("http://10.0.0.101:3333/")
			.addConverterFactory(GsonConverterFactory.create())
			.build();

		rentService = api.create(RentService.class);
		authenticationService = api.create(AuthenticationService.class);
	}
}
