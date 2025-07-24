CXX = g++ -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
HEADERS = iostream fstream memory vector algorithm random cstdlib cmath string
HUMAN = Human.cc Human.cc
DWARF = dwarf.cc dwarf-impl.cc
ELF = Elf.cc Elf-impl.cc
ORCS = Orcs.cc Orcs-impl.cc
MERCHANT = Merchant.cc Merchant-impl.cc
HALFING = Halfing.cc Halfing-impl.cc
DRAGON = Dragon.cc Dragon-impl.cc
ENEMY = Enemy.cc Enemy-impl.cc
POTION = Potion.cc Potion-impl.cc
RH = RestoreHealth.cc RestoreHealth-impl.cc
BA = BoostAtk.cc BoostAtk-impl.cc
BD = BoostDef.cc BoostDef-impl.cc
PH = PoisonHealth.cc PoisonHealth-impl.cc
WA = WoundAtk.cc WoundAtk-impl.cc
WD = WoundDef.cc WoundDef-impl.cc
GOLD = Gold.cc Gold-impl.cc
SG = SmallGold.cc SmallGold-impl.cc
NG = NormalGold.cc NormalGold-impl.cc
MH = MerchantHoard.cc MerchantHoard-impl.cc
DH = DragonHoard.cc DragonHoard-impl.cc
CELL = Cell.cc Cell-impl.cc
FLOOR = Floor.cc Floor-impl.cc
FLOORLEVEL = FloorLevel.cc FloorLevel-impl.cc
GAMEPLAY = GamePlay.cc GamePlay-impl.cc
PC = PlayerCharacter.cc PlayerCharacter-impl.cc
SHADE = shade.cc shade-impl.cc
DROW = Drow.cc Drow-impl.cc
VAMPIRE = vampire.cc vampire-impl.cc
TROLL = troll.cc troll-impl.cc
GOBLIN = goblin.cc goblin-impl.cc
GAMEINIT = GameInit.cc GameInit-impl.cc
MAIN = main.cc
GC = Global_Constants.cc
POSITION = Position.cc Position-impl.cc
EXEC = cc3k

all: one two

one:
	$(CXX) $(HEADERFLAGS) $(HEADERS)

two:
	$(CXX) $(CXXFLAGS) -c $(GC) $(POSITION)
	$(CXX) $(CXXFLAGS) -c $(GOLD) 
	$(CXX) $(CXXFLAGS) -c $(SG) $(NG) $(MH) $(DH)
	$(CXX) $(CXXFLAGS) -c $(PC) 
	$(CXX) $(CXXFLAGS) -c $(SHADE) $(DROW) $(VAMPIRE) $(TROLL) $(GOBLIN)	
	$(CXX) $(CXXFLAGS) -c $(ENEMY) 
	$(CXX) $(CXXFLAGS) -c $(HUMAN) $(DWARF) $(ELF) $(ORCS) $(MERCHANT) $(HALFING) $(DRAGON)
	$(CXX) $(CXXFLAGS) -c $(POTION) 
	$(CXX) $(CXXFLAGS) -c $(RH) $(BA) $(BD) $(PH) $(WA) $(WD)
	$(CXX) $(CXXFLAGS) -c $(CELL)
	$(CXX) $(CXXFLAGS) -c $(FLOOR)
	$(CXX) $(CXXFLAGS) -c $(FLOORLEVEL)
	$(CXX) $(CXXFLAGS) -c $(GAMEPLAY)
	$(CXX) $(CXXFLAGS) -c $(GAMEINIT)
	$(CXX) $(CXXFLAGS) *.o $(MAIN) -o ${EXEC}


clean:
	rm -f $(EXEC)
	rm -f *.o
	rm -rf gcm.cache

.PHONY: all clean one two
