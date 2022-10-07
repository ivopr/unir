package com.pdm.sixth.Models;

import android.graphics.drawable.Drawable;

import lombok.AllArgsConstructor;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@AllArgsConstructor
@NoArgsConstructor
@Getter
@Setter
@EqualsAndHashCode
public class RecycledItem {
	String name, description;
	Integer image;
	Double price;
}
