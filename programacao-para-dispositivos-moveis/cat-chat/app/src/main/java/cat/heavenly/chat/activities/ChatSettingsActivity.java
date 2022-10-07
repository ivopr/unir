package cat.heavenly.chat.activities;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.res.ColorStateList;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.Toast;

import com.google.android.material.textfield.TextInputEditText;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import cat.heavenly.chat.R;
import cat.heavenly.chat.databinding.ActivityChatSettingsBinding;

public class ChatSettingsActivity extends AppCompatActivity {
	private ActivityChatSettingsBinding binding;
	private String oldChatName;
	private String TAG = "ChatSettings";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		binding = ActivityChatSettingsBinding.inflate(getLayoutInflater());

		setContentView(binding.getRoot());

		Bundle data = getIntent().getExtras();
		String chatId = data.getString("chatId");

		DatabaseReference chatRef = FirebaseDatabase
			.getInstance()
			.getReference("/rooms/" + chatId);

		TextInputEditText chatName = binding.chatName;

		chatRef.addListenerForSingleValueEvent(new ValueEventListener() {
			@Override
			public void onDataChange(@NonNull DataSnapshot snapshot) {
				if (snapshot.exists()) {
					oldChatName = snapshot.child("name").getValue().toString();
					chatName.setText(snapshot.child("name").getValue().toString());
				}
			}

			@Override
			public void onCancelled(@NonNull DatabaseError error) {}
		});

		ImageButton goBack = binding.goBack;
		goBack.setOnClickListener(v -> {
			finish();
		});

		Button doSave = binding.doSave;
		doSave.setOnClickListener(v -> {
			if (chatName.getText() != null) {
				String newChatName = chatName.getText().toString();
				if (!newChatName.isEmpty()) {
					if (newChatName.equals(oldChatName)) {
						Toast
							.makeText(
								this,
								"Ambos os nomes são iguais. Não atualizado.",
								Toast.LENGTH_SHORT)
							.show();
					} else {
						chatRef.child("name").setValue(chatName.getText().toString());
						Toast
							.makeText(
								this,
								"Nome do Chat Atualizado!",
								Toast.LENGTH_SHORT)
							.show();
					}
				} else {
					Toast
						.makeText(
							this,
							"O nome do chat não pode ser vazio",
							Toast.LENGTH_SHORT)
						.show();
				}
			} else {
				Toast
					.makeText(
						this,
						"Não foi possivel encontrar a entrada do nome do chat!",
						Toast.LENGTH_SHORT)
					.show();
			}
		});

		doSave.setEnabled(false);

		chatName.addTextChangedListener(new TextWatcher() {
			@Override
			public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) { }

			@Override
			public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) { }

			@Override
			public void afterTextChanged(Editable editable) {
				doSave.setEnabled(!editable.toString().trim().isEmpty() &&
					!editable.toString().equals(oldChatName));
			}
		});
	}
}