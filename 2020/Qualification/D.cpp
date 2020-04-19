#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

enum Effect {
	None       = 1 << 1,
	Complement = 1 << 2,
	Reverse    = 1 << 3,
	Both       = 1 << 4,
	Unknown    = None | Complement | Reverse | Both
};

class Game {
public:
	Game(size_t n_bits)
	: m_array(n_bits, -1)
	, m_probe(n_bits, -1)
	, c_queries{0}
	, probing{false}
	{
	}

	size_t next_guess()
	{
		if (c_queries >= 10 && c_queries % 10 < 2)
		{
			size_t e_pos = find_equal_bits();
			size_t d_pos = find_differing_bits();

			if (e_pos < B()) {
				if (m_probe[e_pos] == -1)
					return e_pos;
			}

			if (d_pos < B()) {
				if (m_probe[d_pos] == -1)
					return d_pos;
			}

			return 0;
		}
		else {
			for (size_t i = 0; i < (B()+1)/2; i++)
			{
				if (m_array[i] == -1)
					return i;
				else if (m_array[B()-i-1] == -1)
					return B()-i-1;
			}
		}

		return 0;
	}

	void provide(int8_t next_bit)
	{
		const size_t B = m_array.size();

		const size_t pos = next_guess();

		if (c_queries > 0 && c_queries % 10 == 0)
		{
			probing = true;
		}

		c_queries++;

		if (!probing) {
			m_array[pos] = next_bit;
		}
		else {
			m_probe[pos] = next_bit;

			size_t e_pos = find_equal_bits();
			size_t d_pos = find_differing_bits();

			int e = Unknown;

			if (e_pos < B) {
				if (m_probe[e_pos] == -1)
					return;

				if (m_probe[e_pos] == m_array[e_pos])
					e &= (None | Reverse);
				else
					e &= (Complement | Both);
			}

			if (d_pos < B) {
				if (m_probe[d_pos] == -1)
					return;

				if (m_probe[d_pos] == m_array[d_pos])
					e &= (None | Both);
				else
					e &= (Complement | Reverse);
			}

//			cerr << "C: " << c_queries << endl;
//			cerr << "Array:  " << get_solution() << endl;
//			cerr << "Probe:  " << get_probe() << endl;
//			cerr << bitset<8>(e) << endl;

			m_probe.assign(m_array.size(), -1);
			probing = false;

			if ((e & Both) != 0) {
				complement();
				reverse();
			}
			else if ((e & Complement) != 0) {
				complement();
			}
			else if ((e & Reverse) != 0) {
				reverse();
			}

//			cerr << "Array*: " << get_solution() << endl;
		}
	}

	bool has_solution() const
	{
		return count(m_array.begin(), m_array.end(), -1) == 0;
	}

	string get_solution() const
	{
		string result(m_array.size(), '-');
		for (size_t i = 0; i < m_array.size(); i++) {
			if (m_array[i] == 1)
				result[i] = '1';
			else if (m_array[i] == 0)
				result[i] = '0';
		}
		return result;
	}

private:
	size_t B() const
	{
		return m_array.size();
	}

	string get_probe() const
	{
		string result(m_probe.size(), '-');
		for (size_t i = 0; i < m_probe.size(); i++) {
			if (m_probe[i] == 1)
				result[i] = '1';
			else if (m_probe[i] == 0)
				result[i] = '0';
		}
		return result;
	}

	size_t find_equal_bits() const
	{
		for (size_t i = 0; i < B(); i++)
		{
			if (m_array[i] != -1 && m_array[i] == m_array[B()-i-1])
				return i;
		}

		return B();
	}

	size_t find_differing_bits() const
	{
		for (size_t i = 0; i < B(); i++)
		{
			if (m_array[i] + m_array[B()-i-1] == 1)
				return i;
		}

		return B();
	}

	void reverse()
	{
		for (size_t i = 0; i < m_array.size() / 2; i++)
		{
			swap(m_array[i], m_array[m_array.size()-i-1]);
		}
	}

	void complement()
	{
		for (size_t i = 0; i < m_array.size(); i++)
		{
			if (m_array[i] != -1)
				m_array[i] = 1 - m_array[i];
		}
	}

	vector<int8_t> m_array;
	vector<int8_t> m_probe;
	size_t c_queries;
	bool probing;
};

int main()
{
    size_t T, B;
    cin >> T >> B;

    for (size_t t = 0; t < T; t++)
    {
        Game game{B};

        while(!game.has_solution())
		{
        	size_t next_guess = game.next_guess();
        	cout << (next_guess+1) << endl;

        	char answer;
        	cin >> answer;

        	if (answer == '0' || answer == '1' )
        		game.provide(static_cast<int8_t>(answer - '0'));
			else
				return 1;
		}

//		cerr << "Case #" << (t+1) << ": " << game.get_solution() << endl;

        cout << game.get_solution() << endl;

        char answer;
		cin >> answer;

		if (answer != 'Y')
			return 1;
    }

    return 0;
}
