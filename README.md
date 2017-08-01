Programming Test – Bomberman (Unreal)

***********************************************************************************************************

MILESTONES:

- Single player version with bombs, destructible walls, and pickups (2-4 hour)

	• Static top-down view on the level or camera that pans in/out depending on distance between players in the level (0.5h)

	X • Procedural generated maps (2h)

	• Implementation of different pickups (0.5h)
		o Longer bomb blasts
		o More bombs
		o Faster run speed

	• Bomb placing by the player (2h)
		o Player is starting with only one bomb that can be active at a time
		o Placing a bomb subtracts one from the count, when the bomb explodes the count goes up again
		o Amount is upgradable with pickups

	• Player death when standing in bomb blast (0.2h)

	• Bomb blasts (1h)
		o Should not be spherical but linear in the four main directions
		o Can penetrate players/pickups when going off (killing/destroying them)
		o Are stopped by walls
		o Trigger other bombs

	• Differentiation between destructible and indestructible walls, destructible walls can spawn random pickups (~30% chance to spawn something) upon destruction (1h)

	• Win conditions (1h)
		o Show win screen when only one player is alive
		o Show a map timer, that counts down and ends the round
		o Show draw when the last players die in the same bomb blast (or chained bombs) or multiple players are alive when the timer runs out
		o After round end, freeze game in its current state

	• Reset option on end screen (0.1h)
		o Starts another round

		
- Multiplayer version over local network or Internet (1-2 hours)

	• Multiplayer over local network or internet (4 Player)
		o Make the characters distinguishable (color, nameplate, …) (0.5h)
		o Create a simple system to start and join a game (0.5h)

		
- Enemy AI that controls other characters until actual players join (1-2 hour)

	• AI enemies that behave like a player (as long as no player has joined)

