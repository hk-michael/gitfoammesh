volScalarField A = UEqn.A();
volVectorField H = UEqn.H();

volScalarField rA = 1.0 / A;

volVectorField HbyA = rA * AH;

fvScalarMatrix pEqn
(
    fvm::laplacian(rA,p)
    ==
    fvc::div(HbyA)
);

pEqn.setReference(pRefCell,pRefValue);

pEqn.solve();

p = alpha*p + (1.0-alpha)*p_old; // 压力松弛

U = rA*H - rA*fvc::grad(p);

phi = fvc::interpolate(U) & mesh.Sf();

U.correctBoundaryConditions();
p.correctBoundaryConditions();

p_old = p;


