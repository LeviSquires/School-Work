Pseudo Code
	Create class Enemy 
		
		class Enemy
		{
		public :
			Enemy(int damage = 10);// defaults damage to 10.
			void Attack() const;
			
		protected :
			int m_Damage;
		};
	Create class Boss
		
		class Boss :
		public Enemy //Boss is derived from the Enemy class.
		{
		public:
			Boss(int damage = 30, int mult = 3); // defaults damage to 30 and multiplier to 3
			~Boss();
			void Attack() const;
			void SpecialAttack() const;
			
		protected :
			int m_DamageMultiplier;
		};
		
	Create a call to attack() for the enemy class
		
		void Enemy::Attack() const
		{
			cout << "Enemy attack inflicts " << m_Damage << " damage.";
		}

	Create a call to attack() and SpecialAttack() for Boss class.
		
		void Boss::Attack() const
		{
			std::cout << "Boss attack inflicts " << m_Damage << " damage.";
		}

		void Boss::SpecialAttack() const
		{
			std::cout << "Boss special attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage.";
		}
		
		Output all this in the main file.
		