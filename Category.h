#pragma once
//! Category, divides game objects into different categories to recieve different commands.
namespace Category
{
	enum Type
	{
		None = 0,
		Scene = 1 << 0,
		PlayerAircraft = 1 << 1,
		AlliedAircraft = 1 << 2,
		EnemyAircraft = 1 << 3,
	};
}