﻿using Fullstack.API.Models;
using Microsoft.EntityFrameworkCore;

namespace Fullstack.API.Data
{
    public class FullstackDbContext : DbContext
    {
        public FullstackDbContext(DbContextOptions options) : base(options)
        {
        }

        public DbSet<Employee> Employees { get; set; }
    }
}
