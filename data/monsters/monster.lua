Monster = {}

function Monster:new()
  new_monster = { health = 20, attack_damage = 10 }
  setmetatable(new_monster, self)
  self.__index = self
  return new_monster
end

function Monster:get_stats()
  return { health = self.health }
end

function Monster:description()
  return "Large monster"
end

function Monster:attack()
  return self.attack_damage, "The monster farts in your general direction"
end

function Monster:take_damage(damage)
  if damage > self.health then
    damage = self.health
    self.health = 0
  else
    self.health = self.health - damage
  end
  result = "Monster takes " .. damage .. " points of damage"
  if self.health == 0 then
    result = result .. "\nMonster is dead!"
  end
  return result
end
