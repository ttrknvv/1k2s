#include "Dictionary.h"

using namespace Dictionary;

Instance Dictionary::Create(const char dictname[DICTNAMEMAXSIZE], int size) {
	bool compareNAMES = strlen(dictname) > DICTNAMEMAXSIZE;
	bool compareDICT = size > DICTMAXSIZE;
	if (compareNAMES) {
		throw THROW01;
	}
	if (compareDICT) {
		throw THROW02;
	}
	Instance dict;
	dict.maxsize = size;
	for (int i = 0; i < strlen(dictname); i++) {
		dict.name[i] = dictname[i];
	}
	dict.dictionary = new Entry[size];
	return dict;
}

void Dictionary::AddEntry(Instance& inst, Entry& ed) {
	bool compareSIZE = inst.size >= inst.maxsize;
	bool compareNAMES = strlen(ed.name) > ENTRYNAMEMAXSIZE;
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == ed.id) {
			throw THROW04;
		}
	}
	if (compareSIZE) {
		throw THROW03;
	}
	inst.dictionary[inst.size].id = ed.id;
	for (int i = 0; i < strlen(ed.name); i++) {
		inst.dictionary[inst.size].name[i] = ed.name[i];
	}
	inst.size++;
	
}

void Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.size - 1; j++) {
				std::swap(inst.dictionary[j], inst.dictionary[j + 1]);
			}
			inst.size--;
			inst.dictionary[inst.size].id = 0;
			*inst.dictionary[inst.size].name = {};
			break;
		}
		else if (i == inst.size - 1) { throw THROW06; }
	}
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {
	bool compareID = true;
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = 0; j < inst.size; j++) {
				if (inst.dictionary[j].id == new_ed.id && j != i) { throw THROW08; }
				else if (j == inst.size - 1) { 
					inst.dictionary[i] = new_ed;
					break; 
				}
			}
			compareID = false;
			break;
		}
	}
	if (compareID) { throw THROW07; }
	
}

void Dictionary::Print(Instance d) {
	std::cout << "---------  " << d.name << "  ---------" << std::endl;
	for (int i = 0; i < d.size; i++) {
		std::cout << d.dictionary[i].id << "\t" << d.dictionary[i].name << std::endl;
	}
}

Entry Dictionary::GetEntry(Instance inst, int id) {
	bool compareID = true;
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			compareID = false;
			return inst.dictionary[i];
		}
	}
	if (compareID) { throw THROW05; }
}

void Dictionary::Delete(Instance& d) {
	delete []d.dictionary;
	d.maxsize = 0;
	d.size = 0;
	*d.name = {};
}




