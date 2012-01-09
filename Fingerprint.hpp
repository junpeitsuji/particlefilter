#pragma once

#include <stdlib.h>  // getenv()���p�̂���
#include <string>    // std::string�N���X
#include <map>       // std::map�N���X
#include <list>      // std::list�N���X
#include <fstream>   // 

// Boost 1.46�̃��C�u�������p�̂��߂̃w�b�_�t�@�C���ǂݍ���
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/list.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace OpenLab {

	namespace io {

		namespace fp {
			// �f�[�^�N���X
			class Location;
			class Fingerprint;

			// �t�B���K�[�v�����g�̈ʒu����\���N���X
			class Location {
			public:
				Location(){}
				~Location(){}
				std::string name; // 
				double x, y, z;

			private:
				friend class boost::serialization::access;
				template <class Archive>
				void serialize(Archive& archive, unsigned int version)
				{
					static_cast<void>(version); // No use
					archive & boost::serialization::make_nvp("Name", name);
					archive & boost::serialization::make_nvp("X", x);
					archive & boost::serialization::make_nvp("Y", y);
					archive & boost::serialization::make_nvp("Z", z);
				}
			};

			// �t�B���K�[�v�����g�̏���ێ�����N���X
			class Fingerprint {
			public:
				Fingerprint(){}
				~Fingerprint(){}

				int                   id;          // ID
				Location              location;    // location of Fingerprint
				std::map<int, double> values;      // map of value in Fingerprint 
				std::map<int, double> deviations;  // 
				std::map<int, int>    nums;        //

			private:
				friend class boost::serialization::access;
				template <class Archive>
				void serialize(Archive& archive, unsigned int version)
				{
					static_cast<void>(version); // No use
					archive & boost::serialization::make_nvp("Id", id);
					archive & boost::serialization::make_nvp("Location", location);
					archive & boost::serialization::make_nvp("Values", values);
					archive & boost::serialization::make_nvp("Deviations", deviations);
					archive & boost::serialization::make_nvp("Nums", nums);
				}
			};


			// ���[�_�[�t�@�N�g���[�N���X
			class FingerprintIOFactory;

			// ���[�_�[�N���X�C���^�t�F�[�X
			class AbstractFingerprintIO;
			// �������[�_�[�N���X
			class RawfileFingerprintIO;
			class XmlFingerprintIO;
		};

	};

};

// ����w�b�_�t�@�C���ǂݍ���
#include "OpenLab/io/fp/AbstractFingerprintIO.h"
#include "OpenLab/io/fp/RawfileFingerprintIO.h"
#include "OpenLab/io/fp/XmlFingerprintIO.h"
#include "OpenLab/io/fp/FingerpintIOFactory.h"

