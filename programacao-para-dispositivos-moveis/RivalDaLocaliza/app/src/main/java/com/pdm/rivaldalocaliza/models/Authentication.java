package com.pdm.rivaldalocaliza.models;

import lombok.Getter;

@Getter
public class Authentication {
	String token, refresh_token;
	User user;
}
