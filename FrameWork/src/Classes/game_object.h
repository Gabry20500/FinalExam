#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>

#include "component.h"
#include "object.h"
#include "tickable.h"
#include "dll_header.h" 

class DECLSPEC GameObject : public Object, public Tickable
{

public:
	GameObject(const std::string name, const bool is_active = true);
	GameObject(const std::string name, const std::vector<Component*> components, const bool is_active = true);
	virtual ~GameObject() = default;

	/// <summary>
	/// Add/Removes a component form the object
	/// </summary>
	/// <param name="component"></param>
	void addComponent(Component* component);
	void removeComponent(Component* component);


	/// <summary>
	/// Return the first components of the given type from the attached components
	/// </summary>
	/// <typeparam name="T">the component to add</typeparam>
	/// <returns></returns>
	template<class T, class = Component>  T* get_component() {

		if (components.size() == 0) return nullptr;

		for (Component* item : components)
		{
			const auto val = dynamic_cast<T*>(item);
			if (!val) continue;;

			return val;
		}

		return nullptr;
	}

	/// <summary>
	/// Return all the components of the given type from the attached components
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<class T> std::vector<T*> get_components()const
	{
		std::vector<T*> result;

		if (components.size() == 0) return result;

		for each (Component * component in this->components)
		{
			const auto val = dynamic_cast<T*>(component);
			if (!val) continue;

			result.push_back(val);
		}

		return result;
	}

	// Inherited via Tickable
	virtual void on_fixed_update(const float delta_time) override;
	virtual void on_update(const float delta_time) override;

private:
	std::vector<Component*> components;
};

#endif
