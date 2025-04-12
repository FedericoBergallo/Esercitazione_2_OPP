#include<iostream>
using namespace std;

template<typename T>
//un numero complesso è della forma z= a+ib, dove a rappresenta la parte reale e b la parte immaginaria 
class complex_number{   //la classe complax number contiene due interi che rappresentano la parte relae/immaginaria
    T a;  //a e b sono gli attributi della mia classe
    T b; 
public:
    complex_number(){ //costruttore di default: viene chiamato quando genero un'istanza senza definire i suoi attributi 
        a=0;
        b=0;
    }
    complex_number(T re, T im){  // costruttore user-defined: chiamato quando genero un'istanza specificando attributi: riceve in input due numeri.
        a=re;
        b=im;
    }
	
	T parte_reale(void) const   //metodo che restituisce la parte reale ( esempio: m.parte_reale() resituisce la parte reale di m)
	{ 		
	return a;
	}
    T parte_immaginaria(void) const  //metodo che restituisce la parte immaginaria ( esempio: m.parte_immaginaria() resituisce la parte immaginaria di m)
	{
		return b;
	}   
    
	complex_number coniugato(void){  //metodo che restituisce il comlesso coniugato
        complex_number<T> coniugato(a,-b);
        return coniugato; 
    }
    complex_number& operator+=(const complex_number& other) {
		T e = a;    //in e memorizzo la parte reale del numero cui applico il metodo   
		T f = b;	//in f memorizzo la parte immaginaria del nuemero cui applico il metodo
		T g = other.a; //in g memorizzo la parte reale (di *other)
		T h = other.b; //in h memorizzo la parte immaginaria (di *other)
		T real = e+g;
		T immag = f+h;
		this->a=real;  //salvo in this il valore aggiornato della parte reale
		this->b=immag;	 //salvo in this il valore aggiornato della parte immaginaria 	
		return *this;
	}
	
	complex_number operator+(const complex_number& other) const {   //overload dell'operatore + 
        complex_number ret = *this; //in m.metodo, this è un puntatore ad m. Qui mi interessa il  valore, quindi dereferenzio
        ret.a += other.a; //con += sommo alla parte reale di ret la parte reale di other, e memorizzo il tutto in ret.a(parte reale di ret) 
        ret.b += other.b;  //anche ret +=other
        return ret;
    }
	complex_number& operator*=(const complex_number& other) {
		T e = a;    //in e memorizzo la parte reale del numero cui applico il metodo   
		T f = b;	//in f memorizzo la parte immaginaria del nuemero cui applico il metodo
		T g = other.a; //in g memorizzo la parte reale (di *other)
		T h = other.b; //in h memorizzo la parte immaginaria (di *other)
		T re =(e*g)-(f*h);
		T im = (e*h)+(f*g);
		this->a=re;  //salvo in this il valore aggiornato della parte reale
		this->b=im;  //salvo in this il valore aggiornato della parte immaginaria
		return *this;
	}
	
	complex_number operator*(const complex_number& other) const {   //overload dell'operatore + 
        complex_number prod = *this; //in m.metodo, this è un puntatore ad m. Qui mi interessa il  valore, quindi de referenzio
		prod *= other;
        return prod;
    }
	complex_number& operator+=(const T& other) {  //con questo operatore mi aspetto di poter fare la somma tra complex_number + T
        T e = a; //in e memorizzo la parte reale del numero cui applico il metodo    
		T f = b; //in f memorizzo la parte immaginaria del nuemero cui applico il metodo
		T g = other; //in g memorizzo la parte reale (di *other che in questo caso è lui stesso)
        T h =0; //in h memorizzo la parte immaginaria (di *other)
		T re= e + g;
		T im= b + h;
		this->a=re;  //salvo in this il valore aggiornato della parte reale
		this->b=im;  //salvo in this il valore aggiornato della parte immaginaria		
		return *this;
	}

	complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	complex_number& operator*=(const T& other) {  //con questo operatore mi aspetto di poter fare: complex_number * T
        T e = a; //in e memorizzo la parte reale del numero cui applico il metodo    
		T f = b; //in f memorizzo la parte immaginaria del nuemero cui applico il metodo
		T g = other; //in g memorizzo la parte reale (di *other che in questo caso è lui stesso)
        T h =0; //in h memorizzo la parte immaginaria (di *other)
		T re =(e*g)-(f*h);
		T im = (e*h)+(f*g);
		this->a=re;  //salvo in this il valore aggiornato della parte reale
		this->b=im;  //salvo in this il valore aggiornato della parte immaginaria		
		return *this;
	}

	complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }	
};
//dopo aver fatto complex +/ * T, voglio poter fare l'"inverso" 

template<typename T>
complex_number<T>
operator+(const T& i, const complex_number<T>& c)
{	
	return c+i;
}
template<typename T>
complex_number<T>
operator*(const T& i, const complex_number<T>& c)
{	
	return c * i;
}
//fornisco un overload dell'operatore "<<" per la rendere stampabile i numeri complessi (elementi della mia classe creata)
template<typename T>
std::ostream& operator << (std::ostream& os, const complex_number<T>& c) {
    if (c.parte_immaginaria() < 0.0)
        os << c.parte_reale() << "-i" << abs(c.parte_immaginaria());
    else
        os << c.parte_reale() << "+i" << c.parte_immaginaria();
    return os;
}


int main(void) {
   complex_number<float> n;  //qui verrà chiamato il costruttore di default che inizializza a 0 parte reale ed immaginaria
   complex_number<double> m(5.0, 5.0);
   complex_number<double> o(7.0, 5.0);
   double d=4.0;
   complex_number<double> result_somma1 = m + o;
   std::cout <<"Il risultato della somma tra m ed o è: " <<result_somma1 <<std::endl;
   
   complex_number<double> result_prodotto1 = m * o;
   std::cout <<"Il risultato del prodotto tra m ed n è: " << result_prodotto1 << std::endl;
   
   complex_number<double> result_somma2= m + d;
   std::cout <<"Il risultato della somma tra m e d è: " << result_somma2 << std::endl;
   
   complex_number<double> result_prodotto2 = m * d;
   std::cout <<"Il risultato del prodotto tra m ed d è: " << result_prodotto2 << std::endl; 
   
   complex_number<double> result_somma3= d + m;
   std::cout <<"Il risultato della somma tra d ed m è: " << result_somma3 << std::endl;

	complex_number<double> result_prodotto3 = d * m;
    std::cout <<"Il risultato del prodotto tra m ed d è: " << result_prodotto3 << std::endl; 
   return 0;
}
