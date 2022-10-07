package com.pdm.rivaldalocaliza.utils;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.Network;
import android.net.NetworkCapabilities;

public class NetworkUtils {
	public static boolean hasInternetConnection(final Context context) {
		final ConnectivityManager connectivityManager = (ConnectivityManager)context.
			getSystemService(Context.CONNECTIVITY_SERVICE);

		final Network network = connectivityManager.getActiveNetwork();
		final NetworkCapabilities capabilities = connectivityManager
			.getNetworkCapabilities(network);

		return capabilities != null
			&& capabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_VALIDATED);
	}
}
