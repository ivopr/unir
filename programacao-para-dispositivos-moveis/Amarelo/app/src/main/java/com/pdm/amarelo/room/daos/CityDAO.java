package com.pdm.amarelo.room.daos;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.pdm.amarelo.room.entities.City;

import java.util.List;

@Dao
public interface CityDAO {
	@Insert
	public void insert(City... cities);

	@Update
	public void update(City... cities);

	@Delete
	public void delete(City city);

	@Query("SELECT * FROM cities")
	public List<City> getCities();

	@Query("SELECT * FROM cities WHERE id = :cityId")
	public City getCityById(Long cityId);

	@Query("SELECT * FROM cities WHERE name = :name")
	public City getCityByName(String name);
}
