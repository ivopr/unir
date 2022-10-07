package cat.heavenly.chat.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

import java.util.List;

import cat.heavenly.chat.R;
import cat.heavenly.chat.entities.Message;
import de.hdodenhof.circleimageview.CircleImageView;
import lombok.AllArgsConstructor;

@AllArgsConstructor
public class MessageAdapter extends RecyclerView.Adapter<MessageAdapter.ViewHolder> {
	List<Message> list;

	@NonNull
	@Override
	public MessageAdapter.ViewHolder onCreateViewHolder(
		@NonNull ViewGroup parent,
		int viewType
	) {
		View v = LayoutInflater
			.from(parent.getContext())
			.inflate(R.layout.recycler_message, parent, false);

		return new MessageAdapter.ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(
		@NonNull MessageAdapter.ViewHolder holder,
		int position
	) {
		Message item = list.get(position);

		holder.userName.setText(item.getUsername());
		holder.message.setText(item.getMessage());
		Glide
			.with(holder.itemView.getContext())
			.load(item.getPhoto())
			.into(holder.profile);
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	@SuppressLint("NotifyDataSetChanged")
	public void update(List<Message> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView userName, message;
		CircleImageView profile;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			userName = itemView.findViewById(R.id.username);
			message = itemView.findViewById(R.id.message_content);
			profile = itemView.findViewById(R.id.profile_image);
		}
	}
}