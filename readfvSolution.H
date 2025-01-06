Info<< "Reading fvSolutino\n" << endl;
IOdictionary fvSolution
(
    IOobject
    (
        "fvSolution",
        runTime.system(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

// scalar alpha(readScalar(fvSolution.lookup("alpha")));
dimensionedScalar alphaD("alpha",dimless,fvSolution);
scalar alpha(alphaD.value());

// scalar pRefCell(readScalar(fvSolution.lookup("pRefCell")));
dimensionedScalar pRefCellD("pRefCell",dimless,fvSolution);
scalar pRefCell(pRefCellD.value());

// scalar pRefValue(readScalar(fvSolution.lookup("pRefValue")));
dimensionedScalar pRefValueD("pRefValue",dimless,fvSolution);
scalar pRefValue(pRefValueD.value());

Info<< "fvSolution parameters" << nl
    << "\trelaxation factor \"alpha\": " << alpha << nl
    << "\tindex of cell containing reference pressure \"pRefCell\": " << pRefCell << nl
    << "\treference pressure value \"pRefValue\": " << pRefValue << nl
    << endl;


