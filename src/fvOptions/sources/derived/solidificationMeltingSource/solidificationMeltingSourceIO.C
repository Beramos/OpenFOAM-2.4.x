/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2014 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "solidificationMeltingSource.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::fv::solidificationMeltingSource::writeData(Ostream& os) const
{
    os  << indent << name_ << endl;
    dict_.write(os);
}


bool Foam::fv::solidificationMeltingSource::read(const dictionary& dict)
{
    if (option::read(dict))
    {
        coeffs_.lookup("Tmelt") >> Tmelt_;
        coeffs_.lookup("L") >> L_;

        coeffs_.readIfPresent("relax", relax_);

        mode_ = thermoModeTypeNames_.read(coeffs_.lookup("thermoMode"));

        coeffs_.lookup("rhoRef") >> rhoRef_;
        coeffs_.readIfPresent("TName", TName_);
        coeffs_.readIfPresent("UName", UName_);

        coeffs_.readIfPresent("Cu", Cu_);
        coeffs_.readIfPresent("q", q_);

        coeffs_.readIfPresent("beta", beta_);

        return true;
    }
    else
    {
        return false;
    }

    return false;
}


// ************************************************************************* //
