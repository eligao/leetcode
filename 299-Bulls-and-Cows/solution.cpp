class Solution {
public:
	string getHint(string secret, string guess) {
		int bull = 0, cow = 0;
		int n = secret.size();
		int secret_count[10] = { 0 }, guess_count[10] = { 0 };
		for (int i = 0; i<n; i++)
		{
			if (secret[i] == guess[i])
				bull++;
			else
			{
				++(secret_count[secret[i] - '0']);
				++(guess_count[guess[i] - '0']);
			}
		}

		for (int i = 0; i<10; i++)
		{
			if (guess_count[i]&& secret_count[i])
				cow+=min(guess_count[i],secret_count[i]);
		}
		stringstream ss;
		ss << bull << 'A' << cow << 'B';
		return ss.str();

	}
};