#pragma once
#include <memory>
#include <stack> 
#include "State.h"

	typedef std::unique_ptr<State> StateRef;

	class StateHandler { 
	private:
		std::stack<StateRef> _states;
		StateRef _newState;
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	public:
		StateHandler(){}
		~StateHandler(){}

		void addState(StateRef newState, bool isReplacing = true); 
		void removeState(); 
		void processStateChanges();
		StateRef& GetActiveState(); 
	};
