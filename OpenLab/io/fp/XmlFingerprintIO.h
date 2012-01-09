#pragma once

#include "Fingerprint.hpp"

namespace OpenLab {

	namespace io {

		namespace fp {

			class XmlFingerprintIO : public AbstractFingerprintIO
			{
			public:
				virtual std::list<Fingerprint> createFingerprintList(const char *filename){
					char *env         = getenv("DATA_SOURCE_PATH");
					char filepath[200];
					sprintf(filepath, "%s/%s", env, filename);

					std::ifstream ifs(filepath);
					boost::archive::xml_iarchive iarchive(ifs);

					// XMLì«çû
					std::list<Fingerprint> fingerprints;
					iarchive >> boost::serialization::make_nvp("Fingerprints", fingerprints);

					return fingerprints;
				}

				virtual void writeFingerprintList(const char *filename, std::list<Fingerprint> fingerprintList){

					char *env         = getenv("DATA_SOURCE_PATH");
					char filepath[200];
					sprintf(filepath, "%s/%s", env, filename);

					std::ofstream ofs(filepath);
					boost::archive::xml_oarchive oarchive(ofs);

					// ÉNÉâÉXèÓïÒÇXMLèoóÕ
					oarchive << boost::serialization::make_nvp("Fingerprints", fingerprintList);

				}
			};

		};

	};

};