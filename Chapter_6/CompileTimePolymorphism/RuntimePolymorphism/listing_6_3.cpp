void carbo_thar(const int& encased_solo) {
	//encased_solo++; // compiler error; modifying const
	auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
	hibernation_sick_solo++;
}