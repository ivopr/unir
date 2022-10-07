package com.pdm.rivaldalocaliza.room.dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.pdm.rivaldalocaliza.room.models.User;

import java.util.List;

@Dao
public interface UserDAO {
	@Insert
	public void insert(User... users);

	@Update
	public void update(User... users);

	@Delete
	public void delete(User user);

	@Query("SELECT * FROM user")
	public List<User> getUsers();
}
