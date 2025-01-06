fvVectorMatrix UEqn
(
    fvm::div(phi,U)
    - fvm::laplacian(nu,U)
    == 
    - fvc::grad(p)
);

UEqn.solve();


