#pragma once
#include <list>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


using autor = string;
using duracion = int;
using cancion = string;


struct info_song{
	autor autor;
	duracion duracion;
	list<cancion>::iterator enPlayList;
	list<cancion>::iterator enRecientes;
};

class iPud {

	unordered_map<cancion, info_song> canciones;

	int duracionPlaylist;

	list<cancion>enPlayList;

	list<cancion>enRecientes;
	

public:
	iPud() {
		duracionPlaylist = 0;
	}

	void addSong(cancion c, autor a, duracion d) {
		if (canciones.count(c) > 0) {
			throw domain_error("Fallo");
		}
		canciones.insert({ c,{a,d,enPlayList.end(),enRecientes.end()} });
	}

	void addToPlayList(cancion c) {
		auto it = canciones.find(c);
		if (it==canciones.end()) {
			throw domain_error("Fallo");
		}
		if (it->second.enPlayList == enRecientes.end()) {
			enPlayList.push_back(it->first);
			duracionPlaylist += it->second.duracion;

		}

	}

	cancion current() {
		if (enPlayList.empty()) {
			throw domain_error("Fallo");
		}
		return enPlayList.front();
	}

	void play() {
		if (!enPlayList.empty()) {
			cancion c = enPlayList.front();
			enPlayList.pop_front();

			auto& info = canciones[c];

			info.enPlayList = enPlayList.end();
			duracionPlaylist -= info.duracion;

			if (info.enRecientes != enRecientes.end()) {
				enRecientes.erase(info.enRecientes);
			}
			info.enRecientes = enRecientes.insert(enRecientes.begin(), c);

		}
	}

	int totalTime() const {
		return duracionPlaylist;
	}

	list<cancion> const& recent(int n) const {
		list<cancion> res;
		for (cancion c : enRecientes) {
			res.push_back(c);
			if (res.size() == n)break;
		}
		return res;
	}

	void deleteSong(cancion c) {
		auto it = canciones.find(c);
		if( it != canciones.end()) {
			auto& info = it->second;
			if (info.enPlayList != enPlayList.end()) {
				enPlayList.erase(info.enPlayList);
				duracionPlaylist -= info.duracion;
			}
			if (info.enRecientes != enRecientes.end()) {
				enRecientes.erase(info.enRecientes);
			}
			canciones.erase(it);
		}
	}
};
