package cat.heavenly.chat.activities;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.content.res.ColorStateList;
import android.os.Bundle;
import android.os.Handler;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.ImageButton;
import android.widget.TextView;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.textfield.TextInputEditText;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.GenericTypeIndicator;
import com.google.firebase.database.ValueEventListener;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Locale;

import cat.heavenly.chat.R;
import cat.heavenly.chat.adapters.MessageAdapter;
import cat.heavenly.chat.databinding.ActivityChatBinding;
import cat.heavenly.chat.entities.Message;

public class ChatActivity extends AppCompatActivity {
	private ActivityChatBinding binding;
	private List<Message> messages = new ArrayList();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		binding = ActivityChatBinding.inflate(getLayoutInflater());
		setContentView(binding.getRoot());

		Bundle data = getIntent().getExtras();
		String chatId = data.getString("chatId");
		TextView chatName = binding.chatName;

		MessageAdapter messageAdapter = new MessageAdapter(messages);

		RecyclerView messagesRecycler = binding.recyclerView;
		LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this);
		messagesRecycler.setLayoutManager(linearLayoutManager);
		messagesRecycler.setAdapter(messageAdapter);

		chatName.setOnClickListener(v -> {
			// Intent da página do chat
			Intent chatSettingsIntent =
				new Intent(
					this,
					ChatSettingsActivity.class
				);

			chatSettingsIntent.putExtra("chatId", chatId);

			startActivity(chatSettingsIntent);
		});

		DatabaseReference chatRef = FirebaseDatabase
			.getInstance()
			.getReference("/rooms/" + chatId);

		chatRef.addValueEventListener(new ValueEventListener() {
			@Override
			public void onDataChange(@NonNull DataSnapshot snapshot) {
				if (snapshot.exists()) {
					chatName.setText(snapshot.child("name").getValue().toString());
					GenericTypeIndicator<List<Message>> t = new GenericTypeIndicator<List<Message>>() {};
					List<Message> firebaseMessages = snapshot.child("messages").getValue(t);

					if (firebaseMessages != null) {
						messages = firebaseMessages;
						messageAdapter.update(messages);
						messagesRecycler.smoothScrollToPosition(messageAdapter.getItemCount() - 1);
					}
				}
			}

			@Override
			public void onCancelled(@NonNull DatabaseError error) {}
		});

		FloatingActionButton sendMessage = binding.sendMessage;
		TextInputEditText message = binding.message;

		message.setOnFocusChangeListener((v, b) -> {
			(new Handler()).postDelayed(() -> {
				messagesRecycler.smoothScrollToPosition(messageAdapter.getItemCount() - 1);
			}, 500);
		});

		sendMessage.setEnabled(false);

		message.addTextChangedListener(new TextWatcher() {
			@Override
			public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) { }

			@Override
			public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) { }

			@Override
			public void afterTextChanged(Editable editable) {
				sendMessage.setEnabled(!editable.toString().trim().isEmpty());
			}
		});

		sendMessage.setOnClickListener(v -> {
			FirebaseUser user = FirebaseAuth.getInstance().getCurrentUser();

			if (message.getText() != null && user != null) {
				SimpleDateFormat date = new SimpleDateFormat("dd/MM/yyyy", Locale.getDefault());
				if (!message.getText().toString().trim().isEmpty()) {
					Message newMessage = new Message(
						message.getText().toString(),
						user.getDisplayName(),
						"" + user.getPhotoUrl(),
						date.format(new Date())
					);

					messages.add(newMessage);
					message.setText("");
					chatRef
						.child("messages")
						.setValue(messages);
				}
			}
		});

		ImageButton goBack = binding.goBack;
		goBack.setOnClickListener(v -> {
			finish();
		});
	}
}