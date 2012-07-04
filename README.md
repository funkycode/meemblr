## MeeTumblr ##
    It's simple qml + Qt client for *harmattan* _(Nokia N9/50)_
    The work is in progress only, and maybe never finished, so get some patience

Copyrights
========
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the **GNU** **General** **Public** **License** as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but **WITHOUT** **ANY** **WARRANTY**; without even the implied warranty of
    **MERCHANTABILITY** or **FITNESS** **FOR** **A** **PARTICULAR** **PURPOSE**.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Setting up environment for developing
	For developing we recommend using on-device debug or using QEMU out of QtCreator.
	1) Setting up dependencies
		As you might be missing the single-sign-on (SSO) oauth packages in your sysroot, you should install them via the madde terminal.
		1. Get the packaged version of the libraries here:
			http://dl.dropbox.com/u/2336306/signon.tar.gz
		2. Extract them to a local folder, keeping folder structure
		3. navigate to your Madde folder (usually located in your QtSDK root)
			cd QtSDK/Madde/bin
		4. List your targets, remember the target name
			./mad list
			Targets:
			<...>
			harmattan_10.2011.34-1_rt1.2  (installed)
		5. set default target
			./mad set harmattan_10.2011.34-1_rt1.2
		6. Install the debs, these should be the only ones missing. If unsure, try to install all debs from both folders.
			./mad-admin xdpkg -i /<path-to-extracted-download>/signon/signon-oauth2plugin/signon-oauth2plugin_0.15.3+0m7_armel.deb 
			./mad-admin xdpkg -i /<path-to-extracted-download>/signon/signon-oauth2plugin/signon-oauth2plugin-dev_0.15.3+0m7_armel.deb
		7. Restart QtCreator
		8. Make clean, rebuild, run qmake
		9. Start QEMU or device debug. 
		10. happy coding / testing !
		

---

#TODO
	*    UI components for each type of post
	*    OAuth — QOauth lib?
	*    Media playback in app and opton to open with other apps/browser
	*    Sharing thru native menu the posts
	*    Sharing thru native menu to tumblr itself
	*    Account managment
	*    Settings
	*    Add more stuff to TODO list
---

#Devs

 	* cyRUS <kornburn@gmail.com>
	* ZogG <thezogg@gmail.com>
	* niwakame <apps@indigoblack.de>

