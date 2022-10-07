package com.pdm.fifth.Retrofit;

import com.pdm.fifth.Retrofit.Services.GithubService;

import lombok.Getter;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

@Getter
public class API {
	Retrofit api;
	GithubService gservice;

	public API() {
		api = new Retrofit.Builder()
			.baseUrl("https://api.github.com/")
			.addConverterFactory(GsonConverterFactory.create())
			.build();

		gservice = api.create(GithubService.class);
	}
}
