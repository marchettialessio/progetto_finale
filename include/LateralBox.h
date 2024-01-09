#ifndef MONOPOLY_LATERALBOX_H_
#define MONOPOLY_LATERALBOX_H_

#include <ostream>
#include <vector>
#include "Player.h"
#include "Box.h"

namespace monopoly   	
{
	class LateralBox final : public Box
	{
		public:
			
			/**
			* 	enumeration of permitted box categories.
			*/
			enum class Category {economy = 0, standard = 1, luxury = 2};
			
			/**
			* 	enumeration of permitted buildings.
			*/
			enum class Building {none = 0, house = 1, hotel = 2};
			
			/**
			*	Default constructor.
			*	Create a default instance of LateralBox.
			*/
			LateralBox();
			
			/**
			*	Class constructor.
			*	Create an instance of LateralBox.
			* 
			* 	@name  the box identifier
			* 	@param category the box category
			*/
			LateralBox(const std::string &name, Category category);
			
			/**
			*	Class constructor.
			*	Create an instance of LateralBox.
			* 
			* 	@name  the box identifier
			* 	@param category the box category
			*	@param owner 	the box owner
			*/
			LateralBox(const std::string &name, Category category, Player* owner);
			
			/**
			*	Destructor.
			*/
			~LateralBox() override { delete owner_; }
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of LateralBox to copy.
			*/
			LateralBox(const LateralBox& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of LateralBox to move.
			*/
			LateralBox(LateralBox&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of LateralBox to assign.
			*/
			LateralBox& operator=(const LateralBox& other);
			
			Category get_category() const { return category_; }
			
			Building get_building() const { return building_; }
			
			int get_price(const int type) const;
			
			bool sell(Player* owner); //sell the box
			
			bool upgrade(); // building level-up
			
			void clear(); // starting game setting
			
			bool is_for_sale() { return owner_ == nullptr; }
			
			std::string show_box() const override;
			
		private:
			Category category_;
			Building building_;
			
			std::vector<int> price_;
			
			Player* owner_;

	};
	
	std::ostream& operator<<(std::ostream& out, const LateralBox& other); //redefinition
}

#endif //MONOPOLY_LATERALBOX_H_
