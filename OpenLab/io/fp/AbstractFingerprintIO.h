#pragma once

#include "Fingerprint.hpp"

namespace OpenLab {

	namespace io {

		namespace fp {

			class AbstractFingerprintIO
			{
			public:
				virtual std::list<Fingerprint> createFingerprintList(const char *filename)=0;
				virtual void writeFingerprintList(const char *filename, std::list<Fingerprint> fingerprintList)=0;

			};

		};

	};

};