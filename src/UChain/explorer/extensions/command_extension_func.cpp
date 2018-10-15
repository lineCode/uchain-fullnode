/**
 * Copyright (c) 2018-2020 uc developers
 *
 * This file is part of UChain-explorer.
 *
 * UChain-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include <functional>
#include <memory>
#include <string>
#include <array>

#include <UChain/explorer/command.hpp>
#include <UChain/explorer/dispatch.hpp>
#include <UChain/explorer/extensions/command_extension.hpp>
#include <UChain/explorer/extensions/command_extension_func.hpp>
#include <UChain/explorer/extensions/commands/shutdown.hpp>
#include <UChain/explorer/extensions/commands/stopmining.hpp>
#include <UChain/explorer/extensions/commands/startmining.hpp>
#include <UChain/explorer/extensions/commands/getinfo.hpp>
#include <UChain/explorer/extensions/commands/getheight.hpp>
#include <UChain/explorer/extensions/commands/getpeerinfo.hpp>
#include <UChain/explorer/extensions/commands/getaddressucn.hpp>
#include <UChain/explorer/extensions/commands/addnode.hpp>
#include <UChain/explorer/extensions/commands/getmininginfo.hpp>
#include <UChain/explorer/extensions/commands/getblockheader.hpp>
#include <UChain/explorer/extensions/commands/fetchheaderext.hpp>
#include <UChain/explorer/extensions/commands/gettx.hpp>
#include <UChain/explorer/extensions/commands/dumpkeyfile.hpp>
#include <UChain/explorer/extensions/commands/importkeyfile.hpp>
#include <UChain/explorer/extensions/commands/importaccount.hpp>
#include <UChain/explorer/extensions/commands/createaccount.hpp>
#include <UChain/explorer/extensions/commands/getaccount.hpp>
#include <UChain/explorer/extensions/commands/deleteaccount.hpp>
#include <UChain/explorer/extensions/commands/listaddresses.hpp>
#include <UChain/explorer/extensions/commands/getnewaddress.hpp>
#include <UChain/explorer/extensions/commands/getblock.hpp>
#include <UChain/explorer/extensions/commands/validateaddress.hpp>
#include <UChain/explorer/extensions/commands/listbalances.hpp>
#include <UChain/explorer/extensions/commands/getbalance.hpp>
#include <UChain/explorer/extensions/commands/listtxs.hpp>
#include <UChain/explorer/extensions/commands/deposit.hpp>
#include <UChain/explorer/extensions/commands/listtokens.hpp>
#include <UChain/explorer/extensions/commands/gettoken.hpp>
#include <UChain/explorer/extensions/commands/secondaryissue.hpp>
#include <UChain/explorer/extensions/commands/getaddresstoken.hpp>
#include <UChain/explorer/extensions/commands/getaccounttoken.hpp>
#include <UChain/explorer/extensions/commands/gettokenview.hpp>
#include <UChain/explorer/extensions/commands/createtoken.hpp>
#include <UChain/explorer/extensions/commands/registermit.hpp>
#include <UChain/explorer/extensions/commands/transfermit.hpp>
#include <UChain/explorer/extensions/commands/listmits.hpp>
#include <UChain/explorer/extensions/commands/getmit.hpp>
#include <UChain/explorer/extensions/commands/registeruid.hpp>
#include <UChain/explorer/extensions/commands/send.hpp>
#include <UChain/explorer/extensions/commands/sendfrom.hpp>
#include <UChain/explorer/extensions/commands/sendmore.hpp>
#include <UChain/explorer/extensions/commands/sendtoken.hpp>
#include <UChain/explorer/extensions/commands/sendtokenfrom.hpp>
#include <UChain/explorer/extensions/commands/swaptoken.hpp>
#include <UChain/explorer/extensions/commands/listuids.hpp>
#include <UChain/explorer/extensions/commands/deletelocaltoken.hpp>
#include <UChain/explorer/extensions/commands/issue.hpp>
#include <UChain/explorer/extensions/commands/burn.hpp>
#include <UChain/explorer/extensions/commands/transfercert.hpp>
#include <UChain/explorer/extensions/commands/issuecert.hpp>
#include <UChain/explorer/extensions/commands/getwork.hpp>
#include <UChain/explorer/extensions/commands/submitwork.hpp>
#include <UChain/explorer/extensions/commands/setminingaccount.hpp>
#include <UChain/explorer/extensions/commands/changepasswd.hpp>
#include <UChain/explorer/extensions/commands/getmemorypool.hpp>
#include <UChain/explorer/extensions/commands/createmultisigtx.hpp>
#include <UChain/explorer/extensions/commands/createrawtx.hpp>
#include <UChain/explorer/extensions/commands/decoderawtx.hpp>
#include <UChain/explorer/extensions/commands/deletemultisig.hpp>
#include <UChain/explorer/extensions/commands/getnewmultisig.hpp>
#include <UChain/explorer/extensions/commands/getpublickey.hpp>
#include <UChain/explorer/extensions/commands/listmultisig.hpp>
#include <UChain/explorer/extensions/commands/sendrawtx.hpp>
#include <UChain/explorer/extensions/commands/signmultisigtx.hpp>
#include <UChain/explorer/extensions/commands/signrawtx.hpp>
#include <UChain/explorer/extensions/commands/uidchangeaddress.hpp>
#include <UChain/explorer/extensions/commands/getuid.hpp>


namespace libbitcoin {
namespace explorer {


void broadcast_extension(const function<void(shared_ptr<command>)> func, std::ostream& os)
{
    using namespace std;
    using namespace commands;

    os <<"\r\n";
    // account
    func(make_shared<createaccount>());
    func(make_shared<getaccount>());
    func(make_shared<deleteaccount>());
    func(make_shared<importaccount>());
    func(make_shared<changepasswd>());
    func(make_shared<getnewaddress>());
    func(make_shared<validateaddress>());
    func(make_shared<listaddresses>());
    func(make_shared<dumpkeyfile>());
    func(make_shared<importkeyfile>());

    os <<"\r\n";
    // system
    func(make_shared<shutdown>());
    func(make_shared<getinfo>());
    func(make_shared<addnode>());
    func(make_shared<getpeerinfo>());

    // miming
    func(make_shared<startmining>());
    func(make_shared<stopmining>());
    func(make_shared<getmininginfo>());
    func(make_shared<setminingaccount>());
    func(make_shared<getwork>());
    func(make_shared<submitwork>());
    func(make_shared<getmemorypool>());

    os <<"\r\n";
    // block & tx
    func(make_shared<getheight>());
    func(make_shared<getblock>());
    func(make_shared<getblockheader>());
    func(make_shared<fetchheaderext>());
    func(make_shared<gettx>());
    func(make_shared<listtxs>());

    // raw tx
    func(make_shared<createrawtx>());
    func(make_shared<decoderawtx>());
    func(make_shared<signrawtx>());
    func(make_shared<sendrawtx>());

    os <<"\r\n";
    // multi-sig
    func(make_shared<getpublickey>());
    func(make_shared<createmultisigtx>());
    func(make_shared<getnewmultisig>());
    func(make_shared<listmultisig>());
    func(make_shared<deletemultisig>());
    func(make_shared<signmultisigtx>());

    os <<"\r\n";
    // ucn
    func(make_shared<send>());
    func(make_shared<sendmore>());
    func(make_shared<sendfrom>());
    func(make_shared<deposit>());
    func(make_shared<listbalances>());
    func(make_shared<getbalance>());
    func(make_shared<getaddressucn>());

    //os <<"\r\n";
    // token
    /*func(make_shared<createtoken>());
    func(make_shared<deletelocaltoken>());
    func(make_shared<issue>());
    func(make_shared<secondaryissue>());
    func(make_shared<sendtoken>());
    func(make_shared<sendtokenfrom>());
    func(make_shared<listtokens>());
    func(make_shared<gettoken>());
    func(make_shared<getaccounttoken>());*/
    // func(make_shared<gettokenview>());
    /*func(make_shared<getaddresstoken>());
    func(make_shared<burn>());
    func(make_shared<swaptoken>());*/

    //os <<"\r\n";
    // cert
    /*func(make_shared<issuecert>());
    func(make_shared<transfercert>());*/

    //os <<"\r\n";
    // mit
    /*func(make_shared<registermit>());
    func(make_shared<transfermit>());
    func(make_shared<listmits>());
    func(make_shared<getmit>());

    os <<"\r\n";*/
    //uid
    /*func(make_shared<registeruid>());
    func(make_shared<uidchangeaddress>());
    func(make_shared<listuids>());
    func(make_shared<getuid>());*/
}

shared_ptr<command> find_extension(const string& symbol)
{
    using namespace std;
    using namespace commands;

    // account
    if (symbol == createaccount::symbol())
        return make_shared<createaccount>();
    if (symbol == getaccount::symbol())
        return make_shared<getaccount>();
    if (symbol == deleteaccount::symbol())
        return make_shared<deleteaccount>();
    if (symbol == changepasswd::symbol())
        return make_shared<changepasswd>();
    if (symbol == validateaddress::symbol())
        return make_shared<validateaddress>();
    if (symbol == getnewaddress::symbol())
        return make_shared<getnewaddress>();
    if (symbol == listaddresses::symbol())
        return make_shared<listaddresses>();
    if (symbol == importaccount::symbol())
        return make_shared<importaccount>();
    if (symbol == dumpkeyfile::symbol() || symbol == "exportaccountasfile")
        return make_shared<dumpkeyfile>();
    if (symbol == importkeyfile::symbol() || symbol == "importaccountfromfile")
        return make_shared<importkeyfile>();

    // system
    if (symbol == shutdown::symbol())
        return make_shared<shutdown>();
    if (symbol == getinfo::symbol())
        return make_shared<getinfo>();
    if (symbol == addnode::symbol())
        return make_shared<addnode>();
    if (symbol == getpeerinfo::symbol())
        return make_shared<getpeerinfo>();

    // mining
    if (symbol == stopmining::symbol() || symbol == "stop")
        return make_shared<stopmining>();
    if (symbol == startmining::symbol() || symbol == "start")
        return make_shared<startmining>();
    if (symbol == setminingaccount::symbol())
        return make_shared<setminingaccount>();
    if (symbol == getmininginfo::symbol())
        return make_shared<getmininginfo>();
    if ((symbol == getwork::symbol()) || (symbol == "eth_getWork"))
        return make_shared<getwork>();
    if ((symbol == submitwork::symbol()) || ( symbol == "eth_submitWork"))
        return make_shared<submitwork>();
    if (symbol == getmemorypool::symbol())
        return make_shared<getmemorypool>();

    // block & tx
    if (symbol == getheight::symbol())
        return make_shared<getheight>();
    if (symbol == "fetch-height")
        return make_shared<getheight>(symbol);
    if (symbol == getblock::symbol())
        return make_shared<getblock>();
    if (symbol == "getbestblockhash")
        return make_shared<getblockheader>(symbol);
    if (symbol == getblockheader::symbol() || symbol == "fetch-header" || symbol == "getbestblockheader")
        return make_shared<getblockheader>();
    if (symbol == fetchheaderext::symbol())
        return make_shared<fetchheaderext>();
    if (symbol == gettx::symbol() || symbol == "gettransaction")
        return make_shared<gettx>();
    if (symbol == "fetch-tx")
        return make_shared<gettx>(symbol);
    if (symbol == listtxs::symbol())
        return make_shared<listtxs>();

    // raw tx
    if (symbol == createrawtx::symbol())
        return make_shared<createrawtx>();
    if (symbol == decoderawtx::symbol())
        return make_shared<decoderawtx>();
    if (symbol == signrawtx::symbol())
        return make_shared<signrawtx>();
    if (symbol == sendrawtx::symbol())
        return make_shared<sendrawtx>();

    // multi-sig
    if (symbol == getpublickey::symbol())
        return make_shared<getpublickey>();
    if (symbol == getnewmultisig::symbol())
        return make_shared<getnewmultisig>();
    if (symbol == listmultisig::symbol())
        return make_shared<listmultisig>();
    if (symbol == deletemultisig::symbol())
        return make_shared<deletemultisig>();
    if (symbol == createmultisigtx::symbol())
        return make_shared<createmultisigtx>();
    if (symbol == signmultisigtx::symbol())
        return make_shared<signmultisigtx>();

    // ucn
    if (symbol == listbalances::symbol())
        return make_shared<listbalances>();
    if (symbol == getbalance::symbol())
        return make_shared<getbalance>();
    if (symbol == getaddressucn::symbol() || symbol == "fetch-balance")
        return make_shared<getaddressucn>();
    if (symbol == deposit::symbol())
        return make_shared<deposit>();
    if (symbol == send::symbol() || symbol == "uidsend")
        return make_shared<send>();
    if (symbol == sendmore::symbol() || symbol == "uidsendmore")
        return make_shared<sendmore>();
    if (symbol == sendfrom::symbol() || symbol == "uidsendfrom")
        return make_shared<sendfrom>();

    // token
    /*if (symbol == createtoken::symbol())
        return make_shared<createtoken>();
    if (symbol == deletelocaltoken::symbol() || symbol == "deletetoken" )
        return make_shared<deletelocaltoken>();
    if (symbol == listtokens::symbol())
        return make_shared<listtokens>();
    if (symbol == gettoken::symbol())
        return make_shared<gettoken>();
    if (symbol == getaccounttoken::symbol())
        return make_shared<getaccounttoken>();*/
    // if (symbol == gettokenview::symbol())
    //     return make_shared<gettokenview>();
    /*if (symbol == getaddresstoken::symbol())
        return make_shared<getaddresstoken>();
    if (symbol == issue::symbol())
        return make_shared<issue>();
    if (symbol == secondaryissue::symbol() || (symbol == "additionalissue") )
        return make_shared<secondaryissue>();
    if (symbol == sendtoken::symbol() || symbol == "uidsendtoken")
        return make_shared<sendtoken>();
    if (symbol == sendtokenfrom::symbol() || symbol == "uidsendtokenfrom")
        return make_shared<sendtokenfrom>();
    if (symbol == burn::symbol())
        return make_shared<burn>();
    if (symbol == swaptoken::symbol())
        return make_shared<swaptoken>();*/

    // cert
    /*if (symbol == transfercert::symbol())
        return make_shared<transfercert>();
    if (symbol == issuecert::symbol())
        return make_shared<issuecert>();*/

    // mit
    /*if (symbol == registermit::symbol())
        return make_shared<registermit>();
    if (symbol == transfermit::symbol())
        return make_shared<transfermit>();
    if (symbol == listmits::symbol())
        return make_shared<listmits>();
    if (symbol == getmit::symbol())
        return make_shared<getmit>();*/

    // uid
    /*if (symbol == registeruid::symbol())
        return make_shared<registeruid>();
    if (symbol == uidchangeaddress::symbol())
        return make_shared<uidchangeaddress>();
    if (symbol == listuids::symbol())
        return make_shared<listuids>();
    if (symbol == getuid::symbol())
        return make_shared<getuid>();*/

    return nullptr;
}

std::string formerly_extension(const string& former)
{
    return "";
}

} // namespace explorer
} // namespace libbitcoin

