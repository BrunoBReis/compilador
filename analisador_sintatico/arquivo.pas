program exemplo73 (input, output);
var n, s, i :  integer;
   procedure soma;
   var q : integer;
   begin
      q:=i*i;
      if (i div 2) * 2 = i
      then
         s:=s+q
      else
         s:=s-q
   end;
begin
   read (n);
   s:=0; i:=0;
   while i<=n do
   begin
      soma; writeln(s); i:=i+1
   end
end.