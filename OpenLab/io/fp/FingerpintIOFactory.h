#pragma once

#include "Fingerprint.hpp"

namespace OpenLab {

	namespace io {

		namespace fp {

			class FingerprintIOFactory {
			public:
				enum Filetype {
					XML,
					FILE
				};

				static AbstractFingerprintIO *createFingerprintIO(enum Filetype type){
					AbstractFingerprintIO *io;

					switch(type){
					case XML:
						io = new XmlFingerprintIO();
						break;
					case FILE:
						io = new RawfileFingerprintIO();
						break;
					default: 
						io = NULL;
						break;
					}

					return io;
				}
			};

		};

	};

};