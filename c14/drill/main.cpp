#include "../../GUI/std_lib.h"

using namespace std;

class B1
	  {
		public:
			virtual void vf ()
			  {
				cout << "B1::vf()" << endl;
			  }

			void f ()
			  {
				cout << "B1::f()" << endl;
			  }

			virtual void pvf () = 0;
	  };

class D1:
	public B1
	  {
		public:
			void vf ()
			  {
				cout << "D1::vf()" << endl;
			  }

			void f ()
			  {
				cout << "D1::f()" << endl;
			  }

			void pvf ()
			  {
				cout << "D1::pvf()" << endl;
			  }
	  };

class D2:
	public D1
	  {
		public:
			void pvf ()
			  {
				cout << "D2::pvf()" << endl;
			  }
	  };

class B2
	  {
		public:
			virtual void pvf () = 0;
	  };

class D21
	:
		public B2
	  {
		public:
			string name {"name"};

			void pvf ()
			  {
				cout << "D21::pvf() -> name = " << name << endl;
			  };
	  };

class D22:
	public B2
	  {
		public:
			int integer {1234};

			void pvf ()
			  {
				cout << "D22::pvf() -> integer = " << integer << endl;
			  };
	  };

void f (B2 &b2)
  {
	b2.pvf();
  }

int main ()
try
  {
//	B1 b1;
//	b1.vf();
//	b1.f();
//	b1.pvf();

	cout << "------------------" << endl;

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	cout << "------------------" << endl;

	B1 &rd1 = d1;
	rd1.vf();
	rd1.f();
	rd1.pvf();

	cout << "------------------" << endl;

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	cout << "------------------" << endl;

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



