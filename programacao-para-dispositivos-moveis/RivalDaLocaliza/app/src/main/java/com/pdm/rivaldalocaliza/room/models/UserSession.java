package com.pdm.rivaldalocaliza.room.models;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "user_session")
public class UserSession {
	@PrimaryKey(autoGenerate = true)
	private Long id;
	private String token;
	private String refresh_token;
}
