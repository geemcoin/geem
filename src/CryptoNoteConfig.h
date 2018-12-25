// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero project
// Copyright (c) 2014-2018, The Forknote developers
// Copyright (c) 2018, Ryo Currency Project
// Copyright (c) 2016-2018, The Karbowanec developers
// Copyright (c) 2017-2018, The Geem developers
//
// This file is part of Geem.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 90; // addresses start with "G"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const size_t   CRYPTONOTE_TX_SPENDABLE_AGE                   = 6;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 7;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1         = DIFFICULTY_TARGET * 3;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1          = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2000000000000000);
const uint64_t COIN                                          = UINT64_C(100000000);
const uint64_t TAIL_EMISSION_REWARD                          = UINT64_C(100000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;

const uint64_t MINIMUM_FEE_V1                                = UINT64_C(100000);
const uint64_t MINIMUM_FEE_V2                                = UINT64_C(100000);
const uint32_t MINIMUM_FEE_V2_HEIGHT                         = 229500;
const uint64_t MINIMUM_FEE                                   = MINIMUM_FEE_V2;
const uint64_t MAXIMUM_FEE                                   = UINT64_C(100000);  //New Fee Structure

const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000000);
const uint64_t MIN_TX_MIXIN_SIZE                             = 2;
const uint64_t MAX_TX_MIXIN_SIZE_V1                          = 50;
const uint64_t MAX_TX_MIXIN_SIZE_V2                          = 20;
const uint64_t MAX_TX_MIXIN_SIZE                             = MAX_TX_MIXIN_SIZE_V2;
const uint32_t MIN_TX_MIXIN_V1_HEIGHT                        = 228800;
const uint32_t MIN_TX_MIXIN_V2_HEIGHT                        = 228900;
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                    = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT / 4 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 17;  // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = 60;  // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

static const uint64_t POISSON_CHECK_TRIGGER = 10; // Reorg size that triggers poisson timestamp check
static const uint64_t POISSON_CHECK_DEPTH = 60;   // Main-chain depth of the poisson check. The attacker will have to tamper 50% of those blocks
static const double POISSON_LOG_P_REJECT = -75.0; // Reject reorg if the probability that the timestamps are genuine is below e^x, -75 = 10^-33

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 7200;
const uint32_t UPGRADE_HEIGHT_V3                             = 229000;
const uint32_t UPGRADE_HEIGHT_V4                             = 50000000;
const uint32_t UPGRADE_HEIGHT_V5                             = 60000000;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "geem";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001e3a4fdb51c029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210117acaa62146ef6f253c70193003df0e5c80ae495ac77260e130fda085cdaa8a6";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  2045;
const int      RPC_DEFAULT_PORT                              =  2046;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const uint32_t P2P_FAILED_ADDR_FORGET_SECONDS                = (60 * 60);     //1 hour
const uint32_t P2P_IP_BLOCKTIME                              = (60 * 60 * 24);//24 hour
const uint32_t P2P_IP_FAILS_BEFORE_BLOCK                     = 10;
const uint32_t P2P_IDLE_CONNECTION_KILL_INTERVAL             = (5 * 60);      //5 minutes

const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "9f10f9c5f431a9f1411d13936228aeafeefc918ce505efe115d8f94a045fa119";

const char* const SEED_NODES[] = { 
  "seed1.geem.io:2045",
  "seed2.geem.io:2045",
  "seed3.geem.io:2045",
  "seed4.geem.io:2045",
  "seed5.geem.io:2045",
  "seed6.geem.io:2045",
  "cloud.geem.io:2045"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
  {7150,        "69c7e57cb576fd0899951c7ea5841d529358682d9ae6fc183051b0663bd84a63" },           // 12/25/2017, 5:37:56 PM
  {7201,        "a07c0cb16114853a2801a4ef68c9c22b9ceb27931e649fdc2ee7f5a7d0e4e99c" },           // 12/25/2017, 8:48:15 PM //V2.0-Start
  {7777,        "36637f9067ab76b3886a826b29f09a0582a345a9cc311315231955c91c43a184" },           // 12/30/2017, 8:55:18 PM
  {8888,        "368eb9d8ff276f133282ea22150c265d7031159e586df6e8b2e2b3b42c2311f3" },           // 1/9/2018, 7:51:32 AM
  {9999,        "18505e185cd92867fe4c9d8eb1160e4da63b53674040bb8c1b36865d873815ca" },           // 3/5/2018, 0:1:10 AM
  {20000,       "9a1413cc5d46dd2b67a0986c5fed5d8513a4c068ed589649335789cb12d5487d" },           // 3/5/2018, 0:10:37 AM //Long-Term
  {22222,	    "0b932de4ff8ef8a6d3ad7031c8e1abe68283da1bc47427201b7ac316d3c3f4fc" },
  {33333,       "0448be8befda190a034155767dd037730761248713f6be04dc356e027063dd6a" },
  {44444,       "639fbbfe5a5b9c40cb44fb2023d05fb1beb0fb31cd7b1b39e9b31187405a4a5e" },
  {55555,       "4c126bf44d79b107805d5ef34a52d78c1a4c25aa4b1dff9a59a3a13f8c06f01e" },
  {66666,       "80d28a5be20ff8e0a07210648e62e838a95979016c06c3a02d4abe2ef48fc34d" },
  {77777,       "ffc11d6988f7519343ff53f96cf2a6fc4a7ae344e3096e898a2b15f7990a2126" },
  {85000,       "0bbd7999ca258794da60a839d13588b8c4338bdc903034ad8c9d6193b7cbe7e5" },		// 25/6/2018, 23:17:29 PM //Long-Term-JSAJ-Sitara
  {88888,       "16ff12a648655834b3142fe2a7c14019c5c72486d2e7532d08938ad15663bcdb" },
  {99999,       "f94c50f8c402379b0c4e9e2c363fb78a11ee07dd4dc11f36e700624f29be9434" },
  {100000,      "46429f94a26d9e93cd258cdcab292794bd04a54746e415740ff12d9b74eeb6cb" },
  {111111,      "2694ccb473aaa42f5705f00daf3d1d7ce2987c07b1bee2ef650b9a8701be6f7f" },
  {122222,      "a5fb88af91d31f3a5560ad4ed1277a3e4ee1aa1487f8835f830877a2b9f93c63" },
  {130000,      "c20d0796e86fd2f6b0d14f25142dc17886a85398944050cdfa3ec900ae6368b9" },
  {133333,      "0bd8f1a865479d522e439b2751aea706282da823a20f2bb8f998548d3aa17368" },
  {135900,      "6fed04437714f81a9d1c40d5e509c323efce12a282d3ff60268b10380822bdbb" },            // 9/8/2018, 4:24:16 PM //Long-Term-JSAJ-Nebula
  {144444,      "92f59721527a34a0224215922330272fb9ace452013c09d07e925dcb7cc9b733" },
  {150000,      "5ab26864e08cb976d3bede7ee0dfbfd10320f3d086352ce544f6a41a7d154e89" },
  {151900,      "280b85af7c8058a8ba1d57efedbfb396a31a6b1298de2944378dbd06a8602b20" },            // 10/02/2018, 1:59:45 AM //Premature-Burning-Long-Term-JSAJ-Nebula
  {155555,      "d0c5ffb0d81d52b769bbfd14dea7550dd6d58acfee648f4a37239e13910e3c5e" },           //  11/10/2018  13:41:45 PM //Nimbus_Dev_Start
  {166666,      "b4ef206a3fbae860ea5ccea1e59e48d28923c7e26077a56181c3e8030bb2810c" },
  {177777,      "87564817e4e3b4c4dc705c739a8d6b9d461ef3cecfded67312adecf2cccde6f2" },
  {179000,      "81b639d5c7b5075e49a668f05b9372f46769838a3c07cd2905e65e3f1bb6218e" },
  {179999,      "faeecdebea958d6f8aacf8d071ff131cfc16864d70266e3f70281e9b37e6f8ba" },
  {181704,      "4bf1a6ce4d48fa526f3e7e3afa1f3c277034cd0571db78349b75b78f4c663a54" },            //  11/14/2018, 4:55:23 AM //10M Supply Block 50% emitted
  {183333,      "fbcad484c80af29ea26a86f654fa55d79b8a06eb033d7ccfd99ab430120859ae" },
  {184444,      "d6f618aa6f1c1b6a52740491c0b446b6946e2cd6aad37ed8cf543e8799b8d146" },
  {185555,      "71779fa87faf091a7ffb21ded12b22ded15d736e3dd3d2a77566ce12c800d8ce" },
  {186666,      "9db36a0d73d56e0802391623d761e5dff217088bba679a33601bf052539778f8" },
  {187777,      "5912db9a1c132d4af3fe497a5f72a8fb1a810228ed54c30f4ec80d0231149ca6" },
  {188888,      "93c8ea668a19defb1f5ca7643c7eb2a7340e192950b1916da152194126c6ab1f" },
  {189999,      "414896ec1e7d45ae616dc94e2880500ddc96add7d98447c08bc4d52866cc8a90" },
  {195000,      "72f8db1b675b796398d61e281b5ddcd44979fb995a49037c6da7d52157890906" },             // 12/04/2018,  3:21:24 PM EST //Long-Term Nimbus V3 Planned
  {199999,      "f90906dc0f05929e48d4d19d5bf212ac99a699df516a0b852b3c321f7e211f78" },
  {200000,      "2e3d962e0773ad0a3f76d313c019d342371fa643ca4a4a6649c3a319c2b39261" }             //  12/10/2018, 9:31:52 PM  EST //Long-Term Halo V4 derived
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



