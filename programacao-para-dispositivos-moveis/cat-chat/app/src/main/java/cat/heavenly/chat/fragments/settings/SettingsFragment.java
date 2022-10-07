package cat.heavenly.chat.fragments.settings;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;

import com.bumptech.glide.Glide;
import com.google.firebase.auth.FirebaseAuth;

import cat.heavenly.chat.R;
import cat.heavenly.chat.databinding.FragmentSettingsBinding;
import de.hdodenhof.circleimageview.CircleImageView;

public class SettingsFragment extends Fragment {
	private FragmentSettingsBinding binding;
	private FirebaseAuth firebaseAuth;
	private TextView youAreConnected, displayName;
	private CircleImageView profilePhoto;
	private Button signOut;

	public View onCreateView(
		@NonNull LayoutInflater inflater,
		ViewGroup container,
		Bundle savedInstanceState
	) {
		binding = FragmentSettingsBinding
			.inflate(inflater, container, false);

		View root = binding.getRoot();

		displayName = binding.displayName;
		profilePhoto = binding.profileImage;
		signOut = binding.signOut;
		youAreConnected = binding.youAreConnectedAs;

		firebaseAuth = FirebaseAuth.getInstance();
		firebaseAuth.addAuthStateListener(auth -> {
			if (auth.getCurrentUser() != null) {
				youAreConnected
					.setText("Você está conectado(a) como");
				displayName.setText(auth.getCurrentUser().getDisplayName());
				Glide
					.with(root.getContext())
					.load(auth.getCurrentUser().getPhotoUrl())
					.into(profilePhoto);

				profilePhoto.setVisibility(View.VISIBLE);
				displayName.setVisibility(View.VISIBLE);
				signOut.setVisibility(View.VISIBLE);
			} else {
				youAreConnected.setText("Você está desconectado(a)");
				profilePhoto.setVisibility(View.INVISIBLE);
				displayName.setVisibility(View.INVISIBLE);
				signOut.setVisibility(View.INVISIBLE);
			}
		});

		signOut.setOnClickListener(v -> {
			firebaseAuth.signOut();
		});

		return root;
	}

	@Override
	public void onDestroyView() {
		super.onDestroyView();
		binding = null;
	}
}