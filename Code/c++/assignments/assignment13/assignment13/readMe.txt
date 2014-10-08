Assignment 13

Pseudo Code
	Create a base class. 
		class Weapons
		{
		public :
			Weapons(int damage)
			void attack() const;
		protected :
			int m_Damage;
		}
	Create two inherited classes from Weapons.
		class Sword :
			public Weapons
		{
		public :
			Sword(int damage = 10) //default damage value of 10.
			void attack() const;
		protected :
			int m_Damage;
		}
		
		class Crossbow :
			public Weapons
		{
		public :
			Crossbow(int damage = 20) //default damage value of 20.
			void attack() const;
			bool isLoaded() const;
			void reload();
		protected :
			int m_Damage;
		}
	Make cpp files for each class that implement all of the declared functions.
	
		#include "Weapons.h"


		Weapons::Weapons(int damage) : m_Damage(damage)
		{
		}

		Weapons::~Weapons()
		{
		}

		void Weapons::Attack() const
		{
			std::cout << "Weapon attack inflicts " << m_Damage << " damage.";
		}
	The Sword cpp file will be exactly the same as this Weapons cpp file.
	
	The Crossbow cpp file will be more complex since the crossbow must be reloaded each time.
		