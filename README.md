Cyclone: A set of Pure Data objects cloned from Max/MSP 
-------

> Cyclone expands Pure Data with objects cloned from cycling74's Max/MSP. It thus provides some level of compatibility between the two environments, helping users of both systems in the development of cross-platform patches. 

--------------------

Pure Data (or just "Pd") project is found at: https://sourceforge.net/p/pure-data/pure-data/ci/master/tree/

Max is found at: https://cycling74.com/

--------------------

<strong>Exerpt from Cyclone's original Readme:</strong>

"Cyclone is a library of Pure Data classes, bringing some level of compatibility between Max/MSP and Pd environments. Although being itself in the early stage of development, it is meant to eventually become part of a much larger project, aiming at unification and standardization of computer musician's tools. 

In its current form, cyclone is mainly for people using both Max and Pd, and thus wanting to develop cross-platform patches."

(the full original readme is provided in this repository at: <https://github.com/porres/pd-cyclone/blob/master/maintenance/README_original.txt>)

-------

<strong>History of cyclone's maintenance up to the present day:</strong>

Cyclone's original author is Krzysztof Czaja, who worked on it mostly from 2002-2005. 

After that, cyclone ended up incorporated into Pd Extended and was eventually under the maintenance of Hans-Christoph Steiner until Pd Extended was left unmaintained (in jan-2013). After that, cyclone was left unmaintained as well. After a while, Fred Jan Kraan did maintain and develop for cyclone from dec-2014 to feb-2016, when development for cyclone was abandoned (though maintenance for his last package is still active). Since feb-2016, an active further development of cyclone is being proposed by Porres & collaborators on this repository.

-------

<strong>About earlier versions and other repositories:</strong>

A copy of the original cyclone page, from the original author (including the cyclone library version 0.1-Alpha54 from 2005) is available at: http://fjkraan.home.xs4all.nl/digaud/puredata/cyclone/cyclone_site/cyclone.html

In the Pd-extended days, under the maintenance of Hans-Christoph Steiner, the 0.1-Alpha55 version of cyclone was introduced and is still found in Pd-extended 0.42-5, released in september 2010. 

Original Repository:

In january of 2013, the release of Pd-extended 0.43 carried the 0.1-Alpha56 version of cyclone, which is found (amongst other things) at the original repository <https://git.puredata.info/cgit/svn2git/libraries/miXed.git/> - this version of cyclone is available as "cyclone-v0-0extended" when searching for externals in Pd Vanilla (since Pd Vanilla 0.47-0).

Fred Jan Kraan's Repository:

Fred Jan Kraan forked the original repository to <https://github.com/electrickery/pd-miXedSon> where he worked on further developments and releases, such as cyclone version 0.1alpha57 from october 2015 (available here: <https://github.com/porres/pd-cyclone/releases/tag/0.1alpha57>).

Cyclone "0.2beta" is the next and last currently released version of Cyclone. It is found in Fred Jan Kraan's repository and also available when searching for externals in Pd Vanilla. But you can check it here too: <https://github.com/porres/pd-cyclone/releases/tag/0.2beta1>.

-------

<strong>About this repository and its Goals:</strong>

Location of this repository is: https://github.com/porres/pd-cyclone. 

When cyclone was been left unmaintained (in February 2016), Porres forked cyclone to this new repository, where developments for a further release have been made since then.

This repository is faithful to the original goal of cyclone in creating an external Pd package with a collection of objects cloned and compatible to Max/MSP objects. 

Cyclone was originally developed in Max/MSP 4 era - but Max has since then introduced new functionalities on some objects in the more recent versions (from Max 5 to Max 7). The current version of Cyclone (0.2beta) still has some objects with functionalities from Max/MSP 4, but with already some objects updated to include some of the new functionalities introduced in Max 5 (but still missing functionalities from Max 6 and Max 7 versions). 

If in agreement to the Pd community, this repository will release updates of the cyclone project (starting with version "0.3-beta-0"). If so be it, besides bug fixes in current existing objects, new/further developments shall include:

<strong>- A)</strong> New functionalities introduced in newer versions of Max (from Max 5 and on) into the already existing objects in cyclone.

<strong>- B)</strong> New objects compatible to the up to date Max version (currently Max 7.2.4). 

This repository/project is open to collaboration to anyone who wishes to work according to the key and central goal of Max/MSP compatibility. Ideally, any possible Max/MSP object could be cloned or updated, but since this is a fair amount of work, collaborators are free to decide and work on what they consider more relevant and important. Any object that has full or "most possible" compatibility to current Max/MSP can be included. 

Some collaborators are already helping coding new objects and updating/fixing old ones, a list of known bugs and things "to do" will be made available with the first release to come from this repository.

Check some stuff we've been doing in our changelog: https://github.com/porres/pd-cyclone/wiki/changelog

Readme file created February 22nd 2016 (last edited, august 12th 2016)

-------
<strong>Building Cyclone</strong>

Since version 0.1-alpha57, cyclone has relied on the new build system called "pd-lib-builder" by Katja Vetter (check the project in: <https://github.com/pure-data/pd-lib-builder>). With this new build system, all you have to do is type "make" and build cyclone in different platforms.

Cyclone originally used to also compile the objects in libraries (such as "hammer" for control objects and "sickle" for signal objects). But in the Pd extended era, only single binaries were available. The new build system system, up to this moment, only builds each object in a separate file as in the old Pd extended days - with the exception of a sub-library (containing 12 non alphanumeric objects). The current maintenance considers to restore the possibility of also compiling cyclone as a library in the same way it was originally developed.
