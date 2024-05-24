#include "../header/Battle.hpp"

Battle::Battle(Character& _player, Enemy& _enemy) : player(&_player) {
  enemies.push_back(&_enemy);
}

Battle::Battle(Character& _player, const std::vector<Enemy&>& _enemies) : player(&_player) {
  for (const auto& e : _enemies) {
    enemies.push_back(&e);
  }
  items = {"Sword", "Potion", "Shield"};
}

Battle::~Battle() {}

void Battle::startBattle() {
  int choice;
  while (true) {
    std::cout << "1. Fight\n2. Items\n3. Run\nChoose an option: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        // Fight
        for (Enemy* enemy : enemies) {
          fight(*player, *enemy);
        }
        break;
      case 2:
        // Items
        std::cout << "Available items:\n";
        for (int i = 0; i < items.size(); ++i) {
          std::cout << i + 1 << ". " << items[i] << "\n";
        }
        std::cout << "Choose an item: ";
        int itemChoice;
        std::cin >> itemChoice;
        if (itemChoice >= 1 && itemChoice <= items.size()) {
          // useItems(*participants[0]);
        } else {
          std::cout << "Invalid choice!\n";
        }
        break;
      case 3:
        // Run (quit)
        run();
        return;
      default:
        std::cout << "Invalid choice!\n";
    }

    if (isPlayerDead() || areEnemiesDead()) {
      break;
    }
  }

  handlePostBattleActions(!isPlayerDead());
}

void Battle::fight(Character& attacker, Enemy& defender) {
  // TODO: character attack enemy
}

void Battle::fight(Enemy& attacker, Character& defender) {
  // TODO: enemy attack back
}

void Battle::useItems(Character& character) {
  // TODO: Implement item usage logic
  std::cout << "Using item...\n";
}

void Battle::run() {
  std::cout << "Running away from battle...\n";
}

bool Battle::isPlayerDead() const {
  // return !participants[0]->isAlive();
}

bool Battle::areEnemiesDead() const {
  // for (int i = 1; i < participants.size(); ++i) {
  //   if (participants[i]->isAlive()) {
  //     return false;
  //   }
  // }
  return true;
}

void Battle::handlePostBattleActions(bool playerWon) {
  if (playerWon) {
    std::cout << "You won the battle!\n";
    // TODO: Implement experience and level up logic here
  } else {
    std::cout << "You lost the battle!\n";
  }
  // TODO: Implement item shop or end game logic here
}