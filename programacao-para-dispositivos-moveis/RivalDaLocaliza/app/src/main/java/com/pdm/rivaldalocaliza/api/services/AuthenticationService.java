package com.pdm.rivaldalocaliza.api.services;

import com.pdm.rivaldalocaliza.models.Authentication;
import com.pdm.rivaldalocaliza.models.Car;
import com.pdm.rivaldalocaliza.models.LoginForm;
import com.pdm.rivaldalocaliza.models.RefreshForm;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.Field;
import retrofit2.http.GET;
import retrofit2.http.POST;

public interface AuthenticationService {
	/**
	 * Executa o Login e retorna o token e o refresh token
	 * @return Authentication
	 */
	@POST("sessions/")
	Call<Authentication> authenticate(@Body LoginForm loginForm);

	/**
	 * Refaz o login com o refresh token, mantendo o token de acesso atualizado
	 * @return Authentication
	 */
	@POST("refresh-token")
	Call<Authentication> reAuthenticate(@Body RefreshForm refreshForm);
}
