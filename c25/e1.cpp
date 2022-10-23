//
// Created by martin on 10/23/22.
//

#include <utility>

#include "../std_lib.h"

struct Message
{
    size_t id;
    string content;
    Message (size_t id, string content) :
        id (id),
        content (std::move (content))
    {

    }
};

struct Node
{
    Node *prev;
    Node *next;
    int i;
    double d;
};

Message *get_input (size_t dev)
{
  auto msg = new Message (123, "XXX");
  return msg;
}

void frag ()
{
  for (size_t i { 0 } ; i < 10 ; ++i)
    {
      Message *p = get_input (0);
      Node *n1 = new Node;
      cout << "p: " << p << endl;
      delete p;
      Node *n2 = new Node;
    }
}

void no_frag ()
{
  for (size_t i { 0 } ; i < 10 ; ++i)
    {
      Message *p = get_input (0);
      Node *n1 = new Node;
      Node *n2 = new Node;
      cout << "p: " << p << endl;
      delete p;
    }
}

void plot_dec_hex_bin (int min, int max)
{
  constexpr auto sz = sizeof (int) * 8;
  for (auto i = min ; i < max ; ++i)
    {
      cout << dec << setw (3) << i
           << hex << setw (5) << "0x" << i
           << setw (sz + 1) << bitset<sz> (i) << endl;
    }
}

using Integer = unsigned int;

void decipher (const Integer *const v, Integer *const w, const Integer *const k)
{
  static_assert (sizeof (Integer) == 4, "size of Integer wrong for TEA");
  Integer y = v[0];
  Integer z = v[1];
  Integer sum = 0xC6EF3720;
  Integer delta = 0x9E3779B9;
  Integer n = 32;

  while (n-- > 0)
    {
      z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
      sum -= delta;
      y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
    }
  w[0] = y;
  w[1] = z;
}

string get_secret ()
{
  const int n_char = 2 * sizeof (Integer);
  const int k_char = 2 * n_char;
  const string filename = "../c25/secret.txt";

  string key = "bs";
  while (key.size () < k_char)
    {
      key += '0';
    }

  ifstream ifs { filename };

  if (!ifs)
    {
      throw runtime_error ("can't open file");
    }

  const auto *k = reinterpret_cast<const Integer *>(key.data ());

  Integer in_ptr[2];
  char out_buffer[n_char + 1];
  out_buffer[n_char] = 0;
  auto *out_ptr = reinterpret_cast<Integer *>(out_buffer);
  ifs.setf (ios_base::hex, ios_base::basefield);

  string secret;
  while (ifs >> in_ptr[0] >> in_ptr[1])
    {
      decipher (in_ptr, out_ptr, k);
      secret.append (out_buffer);
    }
  return secret;
}

int main (int argc, char *argv[])
{
  cout << "### frag ###" << endl;
  frag ();

  cout << "### no frag ###" << endl;
  no_frag ();

  cout << "### dec hex bin ###" << endl;
  plot_dec_hex_bin (-128, 128);

  cout << "### secret ###" << endl;
  cout << get_secret () << endl;

  return EXIT_SUCCESS;
}
